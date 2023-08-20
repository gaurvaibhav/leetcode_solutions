#define op ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
class Solution
{
public:
    vector<int> topologicalSort(vector<vector<int>> &adjacency, vector<int> &degrees, int size)
    {
        op;
        queue<int> q;
        for (int i = 0; i < size; ++i)
            if (degrees[i] == 0)
                q.push(i);
        vector<int> result;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            result.push_back(x);
            for (int y : adjacency[x])
            {
                degrees[y]--;
                if (degrees[y] == 0)
                    q.push(y);
            }
        }
        for (int i = 0; i < size; ++i)
            if (degrees[i] > 0)
                return {};
        return result;
    }

    vector<int> sortItems(int numItems, int numGroups, vector<int> &itemGroups, vector<vector<int>> &beforeItems)
    {
        op;
        for (int i = 0; i < numItems; ++i)
        {
            if (itemGroups[i] == -1)
                itemGroups[i] = numGroups++;
        }
        vector<vector<int>> groupAdjacency(numGroups), itemAdjacency(numItems);
        vector<int> groupDegrees(numGroups, 0), itemDegrees(numItems, 0);
        for (int i = 0; i < numItems; ++i)
        {
            int toItemGroup = itemGroups[i];
            for (int fromItem : beforeItems[i])
            {
                int fromItemGroup = itemGroups[fromItem];
                if (toItemGroup != fromItemGroup)
                {
                    groupAdjacency[fromItemGroup].push_back(toItemGroup);
                    groupDegrees[toItemGroup]++;
                }
                itemAdjacency[fromItem].push_back(i);
                itemDegrees[i]++;
            }
        }
        vector<int> sortedGroups = topologicalSort(groupAdjacency, groupDegrees, numGroups);
        vector<int> sortedItems = topologicalSort(itemAdjacency, itemDegrees, numItems);
        if (sortedGroups.empty() || sortedItems.empty())
            return {};

        vector<vector<int>> itemsInGroup(numGroups);
        for (int i : sortedItems)
            itemsInGroup[itemGroups[i]].push_back(i);

        vector<int> answer;
        for (int i : sortedGroups)
        {
            for (int item : itemsInGroup[i])
            {
                answer.push_back(item);
            }
        }

        return answer;
    }
};