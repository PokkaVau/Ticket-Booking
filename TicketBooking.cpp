#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

struct Ticket {
    int ticketID;
    string customerName;
    string event;
    string date;
    double price;
};

class TicketBookingApp {
private:
    vector<Ticket> tickets;
    int nextTicketID;

public:
    TicketBookingApp() : nextTicketID(1) {}

    void displayMenu() {
        cout << "\n===== Ticket Booking System =====\n";
        cout << "1. Book a Ticket\n";
        cout << "2. View All Tickets\n";
        cout << "3. Cancel a Ticket\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
    }

    void bookTicket() {
        Ticket newTicket;
        newTicket.ticketID = nextTicketID++;

        cout << "Enter customer name: ";
        cin.ignore();
        getline(cin, newTicket.customerName);

        cout << "Enter event name: ";
        getline(cin, newTicket.event);

        cout << "Enter event date (YYYY-MM-DD): ";
        getline(cin, newTicket.date);

        cout << "Enter ticket price: ";
        cin >> newTicket.price;

        tickets.push_back(newTicket);
        cout << "\nTicket booked successfully! Ticket ID: " << newTicket.ticketID << "\n";
    }

    void viewAllTickets() {
        if (tickets.empty()) {
            cout << "\nNo tickets booked yet.\n";
        } else {
            cout << "\n===== Booked Tickets =====\n";
            for (const auto& ticket : tickets) {
                cout << "Ticket ID: " << ticket.ticketID << "\n"
                     << "Customer Name: " << ticket.customerName << "\n"
                     << "Event: " << ticket.event << "\n"
                     << "Date: " << ticket.date << "\n"
                     << "Price: $" << ticket.price << "\n"
                     << "------------------------\n";
            }
        }
    }

    void cancelTicket() {
        int ticketID;
        cout << "Enter Ticket ID to cancel: ";
        cin >> ticketID;

        auto it = find_if(tickets.begin(), tickets.end(), [ticketID](const Ticket& ticket) {
            return ticket.ticketID == ticketID;
        });

        if (it != tickets.end()) {
            tickets.erase(it);
            cout << "\nTicket with ID " << ticketID << " has been canceled.\n";
        } else {
            cout << "\nTicket ID not found.\n";
        }
    }

    void run() {
        int choice;
        do {
            displayMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    bookTicket();
                    break;
                case 2:
                    viewAllTickets();
                    break;
                case 3:
                    cancelTicket();
                    break;
                case 4:
                    cout << "\nExiting the system. Goodbye!\n";
                    break;
                default:
                    cout << "\nInvalid choice. Please try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    TicketBookingApp app;
    app.run();
    return 0;
}
