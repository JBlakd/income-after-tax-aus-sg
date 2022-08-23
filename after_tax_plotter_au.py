import matplotlib.pyplot as plt
import sys


def calc_tax(income):
    if income <= 18200:
        return 0
    elif income <= 45000:
        return (income - 18200) * 0.19
    elif income <= 120000:
        return 5092 + (income - 45000) * 0.325
    elif income <= 180000:
        return 29467 + (income - 120000) * 0.37
    else:
        return 51667 + (income - 180000) * 0.45


gross_incomes = list(range(0, 180000, 100))
after_tax_incomes = [(value - calc_tax(value)) for value in gross_incomes]


if len(sys.argv) >= 2:
    income = float(sys.argv[2])
    print(
        f"after-tax value of {sys.argv[2]} in Australia is {income - calc_tax(float(sys.argv[2]))}"
    )

if "noplot" not in sys.argv:
    plt.plot(gross_incomes, after_tax_incomes)
    plt.show()
