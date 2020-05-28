/*
 * hour_glass.cpp
 *
 *  Created on: May 21, 2020
 *      Author: Aniket Pendse
 */


#include <bits/stdc++.h>
#include <vector>
#include <limits>
using namespace std;

/**
 * \brief This function calculates the maximum sum of the hour glass structure
 * formed by an array
 * @param[in] arr Input array of numbers(It needs to be squared for the logic to work)
 * @return Maximum sum from all possible hour glass from the given array
 */
int hourglassSum(vector<vector<int>> arr)
{
	int max_sum = std::numeric_limits<int>::min();

	uint8_t sq_array_length = arr.size();
	for(uint8_t i = 1; i < (sq_array_length-1); ++i)
	{
		for(uint8_t j = 1; j < (sq_array_length-1); ++j)
		{
			const int temp_sum = arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1]
					             + arr[i][j] + arr[i+1][j-1] + arr[i+1][j]
					             + arr[i+1][j+1];
			if(temp_sum > max_sum)
			{
				max_sum = temp_sum;
			}
		}
	}

	return max_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int> > arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}


