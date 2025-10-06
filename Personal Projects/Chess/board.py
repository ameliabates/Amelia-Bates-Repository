import matplotlib.pyplot as plt
import numpy as np

def draw_chessboard():
    # Create an 8x8 grid of alternating 0s and 1s
    chessboard = np.zeros((8, 8))
    chessboard[1::2, 0::2] = 1  # Fill alternate squares with 1
    chessboard[0::2, 1::2] = 1

    # Create a figure
    plt.figure(figsize=(8, 8))
    ax = plt.gca()

    # Display the chessboard with brown and beige colors
    plt.imshow(chessboard, cmap="copper", interpolation="nearest")

    # Add gridlines to separate squares
    for x in range(9):  # 8 squares + 1 for the border
        plt.axhline(x - 0.5, color="black", linewidth=2)
        plt.axvline(x - 0.5, color="black", linewidth=2)

    # Add labels to rows and columns
    rows = "87654321"
    cols = "abcdefgh"
    ax.set_xticks(np.arange(8))
    ax.set_yticks(np.arange(8))
    ax.set_xticklabels(cols, fontsize=14)
    ax.set_yticklabels(rows, fontsize=14)
    ax.xaxis.tick_top()  # Place column labels at the top


    ax.spines[:].set_visible(False)

    plt.title("Chessboard", fontsize=16, fontweight="bold", pad=20)
    plt.axis("off")  # Turn off axis lines but keep the ticks
    plt.show()


draw_chessboard()
