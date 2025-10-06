import requests
from bs4 import BeautifulSoup

# URL of the IMDb top 250 movies page
url = "https://www.imdb.com/chart/top/"

# Headers to include in the request
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
}

response = requests.get(url, headers=headers)
response.raise_for_status()  # Check for HTTP request errors
movie_list = []
title_list = []

def main():
    soup = BeautifulSoup(response.text, 'html.parser')

    movies = soup.select('li.ipc-metadata-list-summary-item')



    for movie in movies:
        link_tag = movie.select_one('a')
        if link_tag:
            movie_link = link_tag['href']
            movie_link = f"https://www.imdb.com{movie_link}"
        else:
            movie_link = 'N/A'

        year = movie.select_one('.cli-title-metadata-item')
        movie_year = year.get_text(strip=True) if year else 'N/A'

        rating = movie.select_one('[aria-label*="IMDb rating"]')
        movie_rating = rating.get_text(strip=True) if rating else 'N/A'

        name = movie.select_one('h3')  # Adjust the selector if necessary
        movie_title = name.get_text(strip=True) if name else ('N/A')
        movie_name = movie_title.split(". ")
        movie_name = movie_name[1]
        title_list.append(movie_name)

        movie_list.append({
            'movie_name': movie_name,
            'year': movie_year,
            'rating': movie_rating,
            'link': movie_link
        })

    for movie in movie_list:
        print(f"Movie: {movie['movie_name']}, Year: {movie['year']}, Rating: {movie['rating']}")

def movie_inspect(title):
    for movie in movie_list:
        if movie['movie_name'].lower() == title.lower():
            movie_link = movie['link']

            response = requests.get(movie_link, headers=headers)
            response.raise_for_status()
            soup = BeautifulSoup(response.text, 'html.parser')


            summary = soup.select_one('span[data-testid="plot-xl"]').get_text(strip=True) if soup.select_one(
                'span[data-testid="plot-xl"]') else 'N/A'
            director = soup.select_one('a[href*="/name/"]').get_text(strip=True) if soup.select_one(
                'a[href*="/name/"]') else 'N/A'
            cast = [actor.get_text(strip=True) for actor in soup.select('a[href*="/name/"]')[:5]]  # Top 5 cast members

            print(f"\nDetails for {title}:")
            print(f"Summary: {summary}")
            print(f"Director: {director}")
            print(f"Top Cast: {', '.join(cast)}")

            break
    else:
        print(f"Movie {title} not found.")

if __name__ == '__main__':
    main()
    main()
    inspect = input("Would you like to take a closer look at a movie on this list (Y/N): ")

    if inspect == 'Y':
        title = input("What movie: ")
        if title in title_list:
            movie_inspect(title)

    else:
        print("Either rejected or inputted unknown variable")

