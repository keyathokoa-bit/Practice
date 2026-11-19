#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{

    const int MAX_ATTEMPTS = 10;

    int attempts = 0;
    int validCheckins = 0;
    int invalidAttempts = 0;
    int shortVisits = 0;       // 15 - 44 minutes
    int standardVisits = 0;    // 45 - 89 minutes
    int extendedVisits = 0;    // 90 - 180 minutes
    int gymFloorVisits = 0;    // Activity Code 1
    int groupClassVisits = 0;  // Activity Code 2
    int consultations = 0;     // Activity Code 3
    int totalValidMinutes = 0;

    char continueChoice = 'Y';

    while (attempts < MAX_ATTEMPTS && (continueChoice == 'Y' || continueChoice == 'y'))
    {
        attempts++;

        string studentNumber;
        int activityCode;
        int duration;

        cout << "\nAttempt " << attempts << " of " << MAX_ATTEMPTS << endl;
        cout << "Student number: ";
        cin >> studentNumber;
        cin.ignore(1000, '\n');

        cout << "Activity (1=Gym, 2=Group Class, 3=Consultation): ";
        cin >> activityCode;

        cout << "Duration in minutes (15-180): ";
        cin >> duration;


        bool isValidActivity = (activityCode >= 1 && activityCode <= 3);
        bool isValidDuration = (duration >= 15 && duration <= 180);

        if (!isValidActivity || !isValidDuration)
        {
            invalidAttempts++;
            cout << "INVALID CHECK-IN";
            if (!isValidActivity) {
                cout << " - invalid activity";
            }
            if (!isValidDuration) {
                cout << " - invalid duration";
            }
            cout << endl;
        }
        else
        {
            validCheckins++;
            totalValidMinutes += duration;

            if (activityCode == 1)
            {
                gymFloorVisits++;
            }
            else if (activityCode == 2)
            {
                groupClassVisits++;
            }
            else if (activityCode == 3)
            {
                consultations++;
            }

            if (duration >= 15 && duration <= 44)
            {
                shortVisits++;
                cout << "SHORT VISIT" << endl;
            }
            else if (duration >= 45 && duration <= 89)
            {
                standardVisits++;
                cout << "STANDARD VISIT" << endl;
            }
            else if (duration >= 90 && duration <= 180)
            {
                extendedVisits++;
                cout << "EXTENDED VISIT" << endl;
            }

            if (duration >= 120)
            {
                cout << "LONG SESSION CHECK" << endl;
            }
        }

        if (attempts < MAX_ATTEMPTS)
        {
            cout << "Process another check-in? (Y/N): ";
            cin >> continueChoice;
        }
    }

    cout << "\n================= VUKAFIT DAILY CHECK-IN SUMMARY =================" << endl;
    cout << left << setw(26) << "Valid Check-ins" << " : " << validCheckins << endl;
    cout << left << setw(26) << "Invalid Attempts" << " : " << invalidAttempts << endl;
    cout << left << setw(26) << "Short Visits" << " : " << shortVisits << endl;
    cout << left << setw(26) << "Standard Visits" << " : " << standardVisits << endl;
    cout << left << setw(26) << "Extended Visits" << " : " << extendedVisits << endl;
    cout << left << setw(26) << "Gym Floor Visits" << " : " << gymFloorVisits << endl;
    cout << left << setw(26) << "Group Class Visits" << " : " << groupClassVisits << endl;
    cout << left << setw(26) << "Consultations" << " : " << consultations << endl;
    cout << left << setw(26) << "Total Valid Minutes" << " : " << totalValidMinutes << endl;

    cout << fixed << setprecision(2);
    double averageDuration = 0.0;
    if (validCheckins > 0)
    {
        averageDuration = static_cast<double>(totalValidMinutes) / validCheckins;
    }
    cout << left << setw(26) << "Average Visit Duration" << " : " << averageDuration << endl;
    cout << "==================================================================" << endl;

    return 0;
}