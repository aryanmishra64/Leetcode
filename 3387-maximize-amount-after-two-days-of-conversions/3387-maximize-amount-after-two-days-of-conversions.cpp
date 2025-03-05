class Solution 
{
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, 
                     vector<vector<string>>& pairs2, vector<double>& rates2) 
    {
        // Build graphs for both days
        unordered_map<string, unordered_map<string, double>> graph1 = buildGraph(pairs1, rates1);
        unordered_map<string, unordered_map<string, double>> graph2 = buildGraph(pairs2, rates2);

        // Step 1: BFS for Day 1 to get the maximum amounts after conversions
        unordered_map<string, double> day1Amounts = getMaxAmounts(initialCurrency, graph1);

        // Step 2: BFS for Day 2 to maximize the amount further
        unordered_map<string, double> day2Amounts = getMaxAmounts(initialCurrency, graph2, day1Amounts);

        // Return the max amount of initialCurrency after Day 2
        return day2Amounts[initialCurrency];
    }

private:
    // Function to build the graph representation from currency pairs and rates
    unordered_map<string, unordered_map<string, double>> buildGraph(vector<vector<string>>& pairs, vector<double>& rates) 
    {
        unordered_map<string, unordered_map<string, double>> graph;

        for (int i = 0; i < pairs.size(); i++) 
        {
            string start = pairs[i][0];
            string target = pairs[i][1];
            double rate = rates[i];

            // Adding both directions with inverse exchange rate
            graph[start][target] = rate;
            graph[target][start] = 1.0 / rate;
        }

        return graph;
    }

    // BFS function to get maximum amounts for Day 1
    unordered_map<string, double> getMaxAmounts(string startCurrency, unordered_map<string, unordered_map<string, double>>& graph) 
    {
        unordered_map<string, double> maxAmounts;
        maxAmounts[startCurrency] = 1.0; // Start with 1 unit of initialCurrency

        queue<string> q;
        q.push(startCurrency);

        while (!q.empty()) 
        {
            string current = q.front();
            q.pop();
            double currentAmount = maxAmounts[current];

            // Traverse all neighboring currencies
            for (auto& entry : graph[current]) 
            {
                string neighbor = entry.first;
                double rate = entry.second;
                double newAmount = currentAmount * rate;

                // If we find a better conversion, update and continue BFS
                if (newAmount > maxAmounts[neighbor]) 
                {
                    maxAmounts[neighbor] = newAmount;
                    q.push(neighbor);
                }
            }
        }

        return maxAmounts;
    }

    // BFS function for Day 2 using results from Day 1
    unordered_map<string, double> getMaxAmounts(string startCurrency, unordered_map<string, unordered_map<string, double>>& graph,
                                                unordered_map<string, double>& initialAmounts) 
    {
        unordered_map<string, double> maxAmounts = initialAmounts;
        queue<string> q;

        // Start BFS from all currencies obtained on Day 1
        for (const auto& pair : initialAmounts) 
        {
            q.push(pair.first);
        }

        while (!q.empty()) 
        {
            string current = q.front();
            q.pop();
            double currentAmount = maxAmounts[current];

            for (auto& entry : graph[current]) 
            {
                string neighbor = entry.first;
                double rate = entry.second;
                double newAmount = currentAmount * rate;

                // If this conversion yields a better amount, update
                if (newAmount > maxAmounts[neighbor]) 
                {
                    maxAmounts[neighbor] = newAmount;
                    q.push(neighbor);
                }
            }
        }

        return maxAmounts;
    }
};
