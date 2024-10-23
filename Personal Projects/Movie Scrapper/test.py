from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from bs4 import BeautifulSoup
import time


chrome_driver_path = "path_to_chromedriver"


service = Service(chrome_driver_path)
options = webdriver.ChromeOptions()
options.add_argument("--headless")
driver = webdriver.Chrome()


url = "https://www.imdb.com/chart/top/"


movie_list = []
title_list = []


def main():
    driver.get(url)

    time.sleep(5)


    page_source = driver.page_source
    soup = BeautifulSoup(page_source, 'html.parser')

    movies = soup.select('li.ipc-metadata-list-summary-item')

    for movie in movies:
        link_tag = movie.select_one('a')
        if link_tag:
            movie_link = link_tag['href']
            movie_link = f"https://www.imdb.com{movie_link}"
        else:
            movie_link = 'N/A'

        year_tag = movie.select_one('.cli-title-metadata-item')
        movie_year = year_tag.get_text(strip=True) if year_tag else 'N/A'

        rating_tag = movie.select_one('[aria-label*="IMDb rating"]')
        movie_rating = rating_tag.get_text(strip=True) if rating_tag else 'N/A'

        name = movie.select_one('h3')
        movie_title = name.get_text(strip=True) if name else ('N/A')
        movie_name = movie_title.split(". ")
        movie_name = movie_name[1]
        title_list.append(movie_name)

        movie_list.append({
            'movie_name': movie_name,
            'year': movie_year.strip("()"),
            'rating': movie_rating,
            'link': movie_link
        })


    for movie in movie_list:
        print(f"Movie: {movie['movie_name']}, Year: {movie['year']}, Rating: {movie['rating']}, Link: {movie['link']}")


def movie_inspect(title):
    for movie in movie_list:
        if movie['movie_name'].lower() == title.lower():
            movie_link = movie['link']
            print(f"Fetching details for {title} from {movie_link}...")


            driver.get(movie_link)
            time.sleep(3)

            page_source = driver.page_source
            soup = BeautifulSoup(page_source, 'html.parser')


            summary = soup.select_one('span[data-testid="plot-xl"]').get_text(strip=True) if soup.select_one(
                'span[data-testid="plot-xl"]') else 'N/A'
            director = soup.select_one('a[href*="/name/"]').get_text(strip=True) if soup.select_one(
                'a[href*="/name/"]') else 'N/A'
            cast = [actor.get_text(strip=True) for actor in soup.select('a[href*="/name/"]')[:5]]

            print(f"\nDetails for {title}:")
            print(f"Summary: {summary}")
            print(f"Director: {director}")
            print(f"Top Cast: {', '.join(cast)}")

            break
    else:
        print(f"Movie {title} not found.")


if __name__ == '__main__':
    main()
    inspect = input("Would you like to take a closer look at a movie on this list (Y/N): ")

    if inspect.lower() == 'y':
        title = input("What movie: ")
        if title in title_list:
            movie_inspect(title)
        else:
            print("Movie not found in the list.")
    else:
        print("Operation canceled.")

    # Quit the browser once done
    driver.quit()
