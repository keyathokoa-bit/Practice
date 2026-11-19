#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    // Named Constants
    const double BASIC_ACCESS_FEE = 220.00;
    const double ACTIVE_PLUS_FEE = 350.00;
    const double COMPLETE_WELLNESS_FEE = 480.00;

    const double TIER1_DISCOUNT_RATE = 0.07;
    const double TIER2_DISCOUNT_RATE = 0.12;
    const double FITNESS_ASSESSMENT_FEE = 180.00;

    // Variables
    string studentNumber;
    string studentName;
    int membershipCode;
    int months;
    char addAssessment;

    string membershipName;
    double monthlyFee = 0.0;
    double subtotal = 0.0;
    double discountPercentage = 0.0;
    double discountAmount = 0.0;
    double assessmentFee = 0.0;
    double finalAmount = 0.0;

    // 1. Capture Student Details
    cout << "Student number: ";
    cin >> studentNumber;
    cin.ignore(1000, '\n'); // Clear newline before reading full name

    cout << "Student name: ";
    getline(cin, studentName);

    cout << endl;

    // 2. Display Membership Options and Capture Selection
    cout << "1. Basic Access - R220" << endl;
    cout << "2. Active Plus - R350" << endl;
    cout << "3. Complete Wellness - R480" << endl;
    cout << "Select membership: ";
    cin >> membershipCode;

    // Validate Membership Code
    switch (membershipCode)
    {
    case 1:
        membershipName = "Basic Access";
        monthlyFee = BASIC_ACCESS_FEE;
        break;
    case 2:
        membershipName = "Active Plus";
        monthlyFee = ACTIVE_PLUS_FEE;
        break;
    case 3:
        membershipName = "Complete Wellness";
        monthlyFee = COMPLETE_WELLNESS_FEE;
        break;
    default:
        cout << "Error: Invalid membership selection. Program terminated." << endl;
        return 1; // Exit program on invalid input
    }

    // 3. Capture and Validate Months
    cout << "Number of months (1-6): ";
    cin >> months;

    if (months < 1 || months > 6)
    {
        cout << "Error: Invalid duration. Months must be between 1 and 6. Program terminated." << endl;
        return 1; // Exit program on invalid input
    }

    // 4. Capture and Validate Fitness Assessment Selection (Y/N)
    cout << "Add fitness assessment? (Y/N): ";
    cin >> addAssessment;

    addAssessment = toupper(addAssessment); // Handle both lowercase 'y' and uppercase 'Y'

    if (addAssessment == 'Y')
    {
        assessmentFee = FITNESS_ASSESSMENT_FEE;
    }
    else if (addAssessment == 'N')
    {
        assessmentFee = 0.0;
    }
    else
    {
        cout << "Error: Invalid fitness assessment selection. Must enter Y or N. Program terminated." << endl;
        return 1; // Exit program on invalid input
    }

    // 5. Perform Calculations
    subtotal = monthlyFee * months;

    // Tiered Discount Logic
    if (months >= 3 && months <= 5)
    {
        discountPercentage = TIER1_DISCOUNT_RATE;
    }
    else if (months == 6)
    {
        discountPercentage = TIER2_DISCOUNT_RATE;
    }
    else
    {
        discountPercentage = 0.0;
    }

    discountAmount = subtotal * discountPercentage;
    finalAmount = subtotal - discountAmount + assessmentFee;

    // 6. Display Formatted Quotation
    cout << endl;
    cout << "========= VUKAFIT MEMBERSHIP QUOTATION =========" << endl;
    cout << fixed << setprecision(2);
    cout << left << setw(16) << "Student" << ": " << studentNumber << " - " << studentName << endl;
    cout << left << setw(16) << "Membership" << ": " << membershipName << endl;
    cout << left << setw(16) << "Months" << ": " << months << endl;
    cout << left << setw(16) << "Monthly Fee" << ": R" << monthlyFee << endl;
    cout << left << setw(16) << "Subtotal" << ": R" << subtotal << endl;
    cout << left << setw(16) << "Discount" << ": R" << discountAmount << endl;
    cout << left << setw(16) << "Assessment" << ": R" << assessmentFee << endl;
    cout << left << setw(16) << "FINAL AMOUNT" << ": R" << finalAmount << endl;

    return 0;
}