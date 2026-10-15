from collections import Counter


class StatisticsCalculator:
    """Object-oriented calculator for a nonempty list of integers."""

    def __init__(self, numbers: list[int]):
        if not numbers:
            raise ValueError("At least one integer is required")
        self.numbers = list(numbers)

    def mean(self) -> float:
        return sum(self.numbers) / len(self.numbers)

    def median(self) -> float:
        ordered = sorted(self.numbers)
        middle = len(ordered) // 2
        if len(ordered) % 2:
            return float(ordered[middle])
        return (ordered[middle - 1] + ordered[middle]) / 2

    def mode(self) -> tuple[list[int], int]:
        frequencies = Counter(self.numbers)
        highest = max(frequencies.values())
        if highest == 1:
            return [], highest
        return sorted(value for value, count in frequencies.items() if count == highest), highest


def main() -> None:
    try:
        count = int(input("How many integers? "))
        if not 1 <= count <= 10000:
            raise ValueError("Count must be between 1 and 10000")
        values = list(map(int, input(f"Enter {count} integers separated by spaces: ").split()))
        if len(values) != count:
            raise ValueError(f"Expected {count} integers; received {len(values)}")
        calculator = StatisticsCalculator(values)
        print(f"Mean: {calculator.mean():.2f}")
        print(f"Median: {calculator.median():.2f}")
        modes, frequency = calculator.mode()
        if modes:
            print(f"Mode(s): {', '.join(map(str, modes))} (frequency: {frequency})")
        else:
            print("Mode: No mode (all values occur once)")
    except ValueError as exc:
        print(f"Input error: {exc}")


if __name__ == "__main__":
    main()
