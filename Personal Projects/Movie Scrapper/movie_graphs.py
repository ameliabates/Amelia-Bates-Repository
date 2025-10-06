import matplotlib.pyplot as plt
import seaborn as sns
from collections import Counter
from scrappy import movie_list  # Import the movie_list from the original file

def analyze_genres():
    # Extract genres from the movie list
    genre_counter = Counter()
    for movie in movie_list:
        # Simulate genres (adjust if the genre data is part of the original scraping)
        genres = movie.get('genres', [])
        genre_counter.update(genres)

    # Plot top 10 genres
    if genre_counter:
        genres, counts = zip(*genre_counter.most_common(10))
        sns.barplot(x=list(counts), y=list(genres), palette="viridis")
        plt.title("Top 10 Genres in IMDb Top 250 Movies")
        plt.xlabel("Number of Movies")
        plt.ylabel("Genres")
        plt.tight_layout()
        plt.show()
    else:
        print("No genre data available to analyze.")

def analyze_top_actors():
    # Extract top actors from the movie list
    actor_counter = Counter()
    for movie in movie_list:
        cast = movie.get('cast', [])
        actor_counter.update(cast)

    # Plot top 10 actors
    if actor_counter:
        actors, counts = zip(*actor_counter.most_common(10))
        sns.barplot(x=list(counts), y=list(actors), palette="magma")
        plt.title("Top 10 Actors in IMDb Top 250 Movies")
        plt.xlabel("Number of Movies")
        plt.ylabel("Actors")
        plt.tight_layout()
        plt.show()
    else:
        print("No actor data available to analyze.")

if __name__ == '__main__':
    # Menu to select analysis type
    while True:
        print("\nOptions:")
        print("1. Analyze top genres")
        print("2. Analyze top actors")
        print("3. Exit")

        choice = input("Enter your choice (1-3): ")
        if choice == '1':
            analyze_genres()
        elif choice == '2':
            analyze_top_actors()
        elif choice == '3':
            print("Exiting.")
            break
        else:
            print("Invalid choice. Please try again.")
