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


soup = BeautifulSoup(response.text, 'html.parser')


movies = soup.select('li.ipc-metadata-list-summary-item')


movie_list = []

for movie in movies:
    link_tag = movie.select_one('a')
    if link_tag:
        movie_name = link_tag.get_text(strip=True)
        movie_link = link_tag['href']
        movie_link = f"https://www.imdb.com{movie_link}"
    else:
        movie_name = 'N/A'
        movie_link = 'N/A'

    year = movie.select_one('.cli-title-metadata-item')
    movie_year = year.get_text(strip=True) if year else 'N/A'


    rating = movie.select_one('[aria-label*="IMDb rating"]')
    movie_rating = rating.get_text(strip=True) if rating else 'N/A'

    name = movie.select_one('h3')  # Adjust the selector if necessary
    movie_name = name.get_text(strip=True) if name else 'N/A'

    movie_list.append({
        'movie_name': movie_name,
        'year': movie_year,
        'rating': movie_rating,
        'link': movie_link
    })


for movie in movie_list:
    print(f"Movie: {movie['movie_name']}, Year: {movie['year']}, Rating: {movie['rating']}, link: {movie['link']}")

