#include <iostream>
#include <string>
#include <vector>

double get_after_tax_au(double before_tax) {
    if (before_tax < 0) {
        return -1.0;
    } else if (before_tax <= 18200.0) {
        return before_tax - 0.0;
    } else if (before_tax <= 45000.0) {
        return before_tax - ((before_tax - 18200) * 0.19);
    } else if (before_tax <= 120000.0) {
        return before_tax - (5092.0 + (before_tax - 45000) * 0.325);
    } else if (before_tax <= 180000.0) {
        return before_tax - (29467.0 + (before_tax - 120000) * 0.37);
    } else {
        return before_tax - (51667 + (before_tax - 180000) * 0.45);
    }
}

double get_before_tax_au(double after_tax) {
    if (after_tax < 0) {
        return -1.0;
    } else if (after_tax <= get_after_tax_au(18200.0)) {
        return after_tax;
    } else if (after_tax <= get_after_tax_au(45000.0)) {
        return (100 * after_tax - 345800) / 81;
    } else if (after_tax <= get_after_tax_au(120000.0)) {
        return (after_tax - 9533.0) / 0.675;
    } else if (after_tax <= get_after_tax_au(180000.0)) {
        return (after_tax - 14933.0) / 0.63;
    } else {
        return (after_tax - 29333.0) / 0.555;
    }
}

double get_after_tax_sg(double before_tax) {
    if (before_tax < 0) {
        return -1.0;
    } else if (before_tax <= 20000.0) {
        return before_tax - 0.0;
    } else if (before_tax <= 30000.0) {
        return before_tax - ((before_tax - 10000) * 0.02);
    } else if (before_tax <= 40000.0) {
        return before_tax - (200 + (before_tax - 10000) * 0.035);
    } else if (before_tax <= 80000.0) {
        return before_tax - (550.0 + (before_tax - 40000) * 0.07);
    } else if (before_tax <= 120000.0) {
        return before_tax - (3350.0 + (before_tax - 40000) * 0.115);
    } else if (before_tax <= 160000.0) {
        return before_tax - (7950.0 + (before_tax - 40000) * 0.15);
    } else if (before_tax <= 200000.0) {
        return before_tax - (13950.0 + (before_tax - 40000) * 0.18);
    } else if (before_tax <= 240000.0) {
        return before_tax - (21150.0 + (before_tax - 40000) * 0.19);
    } else if (before_tax <= 280000.0) {
        return before_tax - (28750.0 + (before_tax - 40000) * 0.195);
    } else if (before_tax <= 320000.0) {
        return before_tax - (36550.0 + (before_tax - 40000) * 0.2);
    } else if (before_tax <= 500000.0) {
        return before_tax - (44550.0 + (before_tax - 180000) * 0.22);
    } else if (before_tax <= 1000000.0) {
        return before_tax - (84150.0 + (before_tax - 500000) * 0.23);
    } else {
        return before_tax - (199150.0 + (before_tax - 1000000) * 0.24);
    }
}

double get_before_tax_sg(double after_tax) {
    if (after_tax < 0) {
        return -1.0;
    } else if (after_tax <= 20000.0) {
        return after_tax;
    } else if (after_tax <= get_after_tax_sg(30000.0)) {
        return (50 * (after_tax - 200)) / 49;
    } else if (after_tax <= get_after_tax_sg(40000.0)) {
        return (after_tax - 150) / 0.965;
    } else if (after_tax <= get_after_tax_sg(80000.0)) {
        return (after_tax - 2250) / 0.93;
    } else if (after_tax <= get_after_tax_sg(120000.0)) {
        return (after_tax - 1250) / 0.885;
    } else if (after_tax <= get_after_tax_sg(160000.0)) {
        return (after_tax + 1950) / 0.85;
    } else if (after_tax <= get_after_tax_sg(200000.0)) {
        return (after_tax + 6750) / 0.82;
    } else if (after_tax <= get_after_tax_sg(240000.0)) {
        return (after_tax + 13550) / 0.81;
    } else if (after_tax <= get_after_tax_sg(280000.0)) {
        return (after_tax + 20950) / 0.805;
    } else if (after_tax <= get_after_tax_sg(320000.0)) {
        return (after_tax + 28550) / 0.8;
    } else if (after_tax <= get_after_tax_sg(500000.0)) {
        return (after_tax + 4950) / 0.78;
    } else if (after_tax <= get_after_tax_sg(1000000.0)) {
        return (after_tax - 30850) / 0.77;
    } else {
        return (after_tax - 40850) / 0.76;
    }
}

int main() {
    while (true) {
        std::cout << "Note: We are assuming that SGD and AUD are worth the same because most of the time, they usually are.\n";
        std::cout << "Select one option and press Enter:\n";
        std::cout << "1. I get paid this much in Singapore. How much do I need to get paid in Australia to take home the equivalent amount after tax?\n";
        std::cout << "2. I get paid this much in Australia. How much do I need to get paid in Singapore to take home the equivalent amount after tax?\n";
        std::cout << "3. I take home this much in Singapore. How much do I need to get paid in Australia to take home the equivalent amount after tax?\n";
        std::cout << "4. I take home this much in Australia. How much do I need to get paid in Singapore to take home the equivalent amount after tax?\n";
        std::cout << "Selection: ";

        int option;
        std::cin >> option;

        std::cout << "Enter amount: ";
        int amount;
        std::cin >> amount;

        switch (option) {
            case 1: {
                double after_tax = get_after_tax_sg(amount);
                std::cout << "I get paid $" << amount << " in Singapore. This means I take home $" << after_tax << '\n';
                std::cout << "To take home the equivalent amount in Australia, I need to get paid $" << get_before_tax_au(after_tax) << " in Australia.\n";
                break;
            }
            case 2: {
                double after_tax = get_after_tax_au(amount);
                std::cout << "I get paid $" << amount << " in Australia. This means I take home $" << after_tax << '\n';
                std::cout << "To take home the equivalent amount in Singapore, I need to get paid $" << get_before_tax_sg(after_tax) << " in Singapore.\n";
                break;
            }
            case 3: {
                std::cout << "I take home $" << amount << " in Singapore.\n";
                std::cout << "To take home the equivalent amount in Australia, I need to get paid $" << get_before_tax_au(amount) << " in Australia.\n";
                break;
            }
            case 4: {
                std::cout << "I take home $" << amount << " in Australia.\n";
                std::cout << "To take home the equivalent amount in Singapore, I need to get paid $" << get_before_tax_sg(amount) << " in Singapore.\n";
                break;
            }
            default:
                std::cout << "Exiting.\n";
                return 0;
        }

        std::cout << "Press enter to continue...";
        std::cin.ignore();
        std::cin.get();
        std::cout << "\n";
    }
    return 0;
}
