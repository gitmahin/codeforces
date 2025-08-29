#include <iostream>
#include <sstream>
#include <vector>

class Utility
{
public:
    void getStringSplitingBySpaceNConvertToArrayOfINT(const std::string &value, std::vector<int> &tokens)
    {
        std::stringstream ss(value);
        std::string token;
        while (ss >> token)
        {
            tokens.push_back(stoi(token));
        };
    };
};

int main()
{
    int n, k, numOfAdvancedContestants = 0;
    std::string scoreString;
    std::cin >> n >> k;
    std::getline(std::cin >> std::ws, scoreString);
    std::vector<int> scores;

    if (1 <= k <= n <= 50)
    {
        Utility utility;
        utility.getStringSplitingBySpaceNConvertToArrayOfINT(scoreString, scores);

        int scoreInputLength = scores.size();
        if (n <= scoreInputLength)
        {
            for (int i = 0; i < n; i++)
            {
                if (scores[i] >= scores[k - 1] && scores[i] > 0)
                {
                    numOfAdvancedContestants++;
                }
            }
        }
    }

    std::cout << numOfAdvancedContestants << std::endl;
    return 0;
}