import matplotlib.pyplot as plt


def calc_tax(income):
    if income <= 30000:
        return 0 + (income - 20000) * 0.02
    elif income <= 40000:
        return 200 + (income - 30000) * 0.035
    elif income <= 80000:
        return 550 + (income - 40000) * 0.07
    elif income <= 120000:
        return 3350 + (income - 80000) * 0.115
    elif income <= 160000:
        return 7950 + (income - 120000) * 0.15
    elif income <= 200000:
        return 13950 + (income - 160000) * 0.18
    elif income <= 240000:
        return 21150 + (income - 200000) * 0.19
    elif income <= 280000:
        return 28750 + (income - 240000) * 0.195
    elif income <= 320000:
        return 36550 + (income - 280000) * 0.2
    elif income <= 500000:
        return 44550 + (income - 320000) * 0.22
    elif income <= 1000000:
        return 84150 + (income - 500000) * 0.23
    else:
        return 199150 + (income - 1000000) * 0.24


gross_incomes = list(range(0, 180000, 100))
after_tax_incomes = [(value - calc_tax(value)) for value in gross_incomes]

plt.plot(gross_incomes, after_tax_incomes)
plt.show()
