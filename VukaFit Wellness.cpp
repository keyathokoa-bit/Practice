
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{

    string programmes[3] = { "Yoga", "Strength", "Wellness Workshop" };
    string days[5] = { "Mon", "Tue", "Wed", "Thu", "Fri" };

    int attendance[3][5] = {
        {24, 31, 28, 35, 30}, // Yoga attendance
        {38, 42, 36, 45, 41}, // Strength attendance
        {18, 22, 25, 20, 27}  // Wellness Workshop attendance
    };

    cout << "================== VUKAFIT WEEKLY ANALYTICS ==================" << endl;

    // Header Display
    cout << left << setw(18) << "Programme";
    for (int j = 0; j < 5; j++)
    {
        cout << right << setw(7) << days[j];
    }
    cout << right << setw(10) << "Total" << right << setw(10) << "Average" << endl;

    int grandTotal = 0;
    int totalCells = 3 * 5;
    int highDemandCount = 0;

    int maxProgrammeTotal = -1;
    string topProgramme = "";

    int weekdayTotals[5] = { 0, 0, 0, 0, 0 };

    // 2. Traversal & Row Processing (Programmes)
    for (int i = 0; i < 3; i++)
    {
        cout << left << setw(18) << programmes[i];

        int rowTotal = 0;
        int maxDayIndex = 0;
        int maxDayValue = attendance[i][0];

        for (int j = 0; j < 5; j++)
        {
            int val = attendance[i][j];
            rowTotal += val;
            weekdayTotals[j] += val; // Accumulate for weekday totals

            // Check for HIGH DEMAND (40 or greater)
            if (val >= 40)
            {
                highDemandCount++;
                cout << right << setw(4) << val << " HD";
            }
            else
            {
                cout << right << setw(7) << val;
            }

            // Track highest attendance day for this programme
            if (val > maxDayValue)
            {
                maxDayValue = val;
                maxDayIndex = j;
            }
        }

        grandTotal += rowTotal;
        double rowAverage = static_cast<double>(rowTotal) / 5.0;

        cout << right << setw(10) << rowTotal << right << setw(10) << fixed << setprecision(2) << rowAverage << endl;

        // Display highest day for the current programme
        cout << "  Highest day for " << programmes[i] << ": " << days[maxDayIndex] << " (" << maxDayValue << ")" << endl;

        // Track top programme
        if (rowTotal > maxProgrammeTotal)
        {
            maxProgrammeTotal = rowTotal;
            topProgramme = programmes[i];
        }
    }

    // 3. Day Totals & Busiest Weekday Analysis
    cout << "\nDay totals:" << endl;
    int maxWeekdayTotal = -1;
    int busiestDayIndex = 0;

    for (int j = 0; j < 5; j++)
    {
        cout << days[j] << ": " << weekdayTotals[j] << endl;

        if (weekdayTotals[j] > maxWeekdayTotal)
        {
            maxWeekdayTotal = weekdayTotals[j];
            busiestDayIndex = j;
        }
    }

    // 4. Overall Analytics Summary Display
    double overallAverage = static_cast<double>(grandTotal) / totalCells;

    cout << endl;
    cout << left << setw(22) << "Busiest weekday" << " : " << days[busiestDayIndex] << " (" << maxWeekdayTotal << ")" << endl;
    cout << left << setw(22) << "Top programme" << " : " << topProgramme << " (" << maxProgrammeTotal << ")" << endl;
    cout << left << setw(22) << "HIGH DEMAND values" << " : " << highDemandCount << endl;
    cout << left << setw(22) << "Grand total" << " : " << grandTotal << endl;
    cout << left << setw(22) << "Overall average" << " : " << fixed << setprecision(2) << overallAverage << endl;
    cout << "==============================================================" << endl;

    return 0;
}