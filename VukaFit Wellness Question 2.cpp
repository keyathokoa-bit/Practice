#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


void displaySessionMenu();
double getSessionRate(int sessionCode);
bool validParticipants(int participants);
double calculateSubtotal(double rate, int participants);
double calculateDiscount(double subtotal, int participants);
double calculateWeekendSurcharge(double amountAfterDiscount, char saturday);
void displayBookingSummary(string bookingRef, string sessionName,
    int participants, double subtotal,
    double discount, double surcharge,
    double finalTotal);

int main()
{
    string bookingRef;
    int sessionCode;
    int participants;
    char saturday;

    string sessionName = "";
    double rate = 0.0;
    double subtotal = 0.0;
    double discount = 0.0;
    double amountAfterDiscount = 0.0;
    double surcharge = 0.0;
    double finalTotal = 0.0;

    // 1. Capture Booking Reference
    cout << "Booking reference: ";
    cin >> bookingRef;

    // 2. Display Session Menu and Get Selection
    displaySessionMenu();
    cout << "Session code: ";
    cin >> sessionCode;

    // Get Session Rate & Map Session Name
    rate = getSessionRate(sessionCode);
    if (rate == 0.0)
    {
        cout << "Error: Invalid session code. Program terminated." << endl;
        return 1;
    }

    if (sessionCode == 1)
    {
        sessionName = "Yoga Fundamentals";
    }
    else if (sessionCode == 2)
    {
        sessionName = "Strength Circuit";
    }
    else if (sessionCode == 3)
    {
        sessionName = "Stress Management";
    }

    // 3. Capture and Validate Participants
    cout << "Participants (1-12): ";
    cin >> participants;

    if (!validParticipants(participants))
    {
        cout << "Error: Invalid participant count. Must be between 1 and 12. Program terminated." << endl;
        return 1;
    }

    // 4. Capture and Validate Saturday Option
    cout << "Saturday booking? (Y/N): ";
    cin >> saturday;

    saturday = toupper(saturday);
    if (saturday != 'Y' && saturday != 'N')
    {
        cout << "Error: Invalid response. Enter Y or N. Program terminated." << endl;
        return 1;
    }

    // 5. Calculations
    subtotal = calculateSubtotal(rate, participants);
    discount = calculateDiscount(subtotal, participants);
    amountAfterDiscount = subtotal - discount;
    surcharge = calculateWeekendSurcharge(amountAfterDiscount, saturday);
    finalTotal = amountAfterDiscount + surcharge;

    // 6. Display Summary
    displayBookingSummary(bookingRef, sessionName, participants, subtotal, discount, surcharge, finalTotal);

    return 0;
}

// Function Definitions

// Displays the available session choices
void displaySessionMenu()
{
    cout << "1. Yoga Fundamentals - R75" << endl;
    cout << "2. Strength Circuit - R110" << endl;
    cout << "3. Stress Management - R90" << endl;
}

// Returns the hourly rate per participant based on session code
double getSessionRate(int sessionCode)
{
    switch (sessionCode)
    {
    case 1:
        return 75.00;
    case 2:
        return 110.00;
    case 3:
        return 90.00;
    default:
        return 0.0; // Invalid code indicator
    }
}

// Validates whether participant count is between 1 and 12
bool validParticipants(int participants)
{
    return (participants >= 1 && participants <= 12);
}

// Calculates base subtotal before discounts
double calculateSubtotal(double rate, int participants)
{
    return rate * participants;
}

// Calculates 10% group discount for 8 or more participants
double calculateDiscount(double subtotal, int participants)
{
    if (participants >= 8)
    {
        return subtotal * 0.10;
    }
    return 0.0;
}

// Calculates 15% weekend surcharge on post-discount amount
double calculateWeekendSurcharge(double amountAfterDiscount, char saturday)
{
    if (saturday == 'Y')
    {
        return amountAfterDiscount * 0.15;
    }
    return 0.0;
}

// Formats and displays the final booking summary
void displayBookingSummary(string bookingRef, string sessionName,
    int participants, double subtotal,
    double discount, double surcharge,
    double finalTotal)
{
    double costPerParticipant = finalTotal / participants;

    cout << endl;
    cout << "========== VUKAFIT BOOKING SUMMARY ==========" << endl;
    cout << fixed << setprecision(2);
    cout << left << setw(22) << "Booking Ref" << ": " << bookingRef << endl;
    cout << left << setw(22) << "Session" << ": " << sessionName << endl;
    cout << left << setw(22) << "Participants" << ": " << participants << endl;
    cout << left << setw(22) << "Subtotal" << ": R" << subtotal << endl;
    cout << left << setw(22) << "Group Discount" << ": R" << discount << endl;
    cout << left << setw(22) << "Weekend Surcharge" << ": R" << surcharge << endl;
    cout << left << setw(22) << "Final Total" << ": R" << finalTotal << endl;
    cout << left << setw(22) << "Cost per Participant" << ": R" << costPerParticipant << endl;
}