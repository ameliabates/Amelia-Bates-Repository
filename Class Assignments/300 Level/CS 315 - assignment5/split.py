class Splitting:
    def __init__(self, dic_file):
        self.dictionary = set()
        self.load_dictionary(dic_file)

    def load_dictionary(self, dic_file):
        with open(dic_file, 'r') as dic:
            for line in dic:
                word = line.strip()
                self.dictionary.add(word)

    def can_split(self, phrase):
        length = len(phrase)
        split_table = [False] * (length + 1)
        split_positions = [-1] * (length + 1)
        split_table[length] = True  # An empty string can be split

        for i in range(length - 1, -1, -1):  # opposite direction
            for j in range(i + 1, length + 1):
                if phrase[i:j] in self.dictionary and split_table[j]:
                    split_table[i] = True
                    split_positions[i] = j

        return split_table[0], split_positions

    def find_split_sequence(self, phrase):
        can_split, split_positions = self.can_split(phrase)
        i = 0
        if can_split is True:
            sentence = []
            while i < len(phrase):
                sentence.append(phrase[i:split_positions[i]])
                i = split_positions[i]
            return sentence

        return None


if __name__ == "__main__":
    dictionary = Splitting("diction10k.txt")
    C = open(input("File name: ").strip(), "r")
    num = 0
    next(C)
    for case in C:
        phrase = case.strip()

        print(f"\nphrase {num + 1}")
        print(phrase)
        print("\noutput", num + 1)
        split = dictionary.find_split_sequence(phrase)

        if split is not None:
            print("YES, can split.")
            print(" ".join(split))
        else:
            print("NO, cannot split.")
        num += 1

        