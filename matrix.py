class Matrix:
    def __init__(self, rows):
        self.original_rows = rows

    def is_match(self, other):
        if len(self.original_rows) != len(other.original_rows):
            return False
        for row1, row2 in zip(self.original_rows, other.original_rows):
            even1 = sum(x for x in row1 if x % 2 == 0)
            odd1 = sum(x for x in row1 if x % 2 != 0)
            even2 = sum(x for x in row2 if x % 2 == 0)
            odd2 = sum(x for x in row2 if x % 2 != 0)
            if even1 != even2 or odd1 != odd2:
                return False
        return True

    def format_with_arrow(self, other):
        lines = []
        for row1, row2 in zip(self.original_rows, other.original_rows):
            left = ' '.join(map(str, row1))
            right = ' '.join(map(str, row2))
            lines.append(f"{left} → {right}")
        return '\n'.join(lines)

class MatrixFileHandler:
    @staticmethod
    def read_matrices(filename):
        matrices = []
        with open(filename, encoding="utf-8") as f:
            current = []
            for line in f:
                line = line.strip()
                if line:
                    current.append(list(map(int, line.split())))
                else:
                    if current:
                        matrices.append(Matrix(current))
                        current = []
            if current:
                matrices.append(Matrix(current))
        return matrices

class MatrixProcessor:
    @staticmethod
    def print_matching_pairs(matrices):
        found = False
        n = len(matrices)
        printed_pairs = set()
        for i in range(n):
            for j in range(i+1, n):  # Только (i, j) где i < j
                if matrices[i].is_match(matrices[j]):
                    found = True
                    pair_id = (i, j)
                    if pair_id not in printed_pairs:
                        print(f"Матрица {i+1}:")
                        print(matrices[i].format_with_arrow(matrices[j]))
                        print()
                        printed_pairs.add(pair_id)
        if not found:
            print("Нет подходящих пар")

def main():
    matrices = MatrixFileHandler.read_matrices(r"C:\Users\pixel\PyCharmProjects\Matrix\input.txt")
    MatrixProcessor.print_matching_pairs(matrices)

if __name__ == "__main__":
    main()
