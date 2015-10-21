int maximumGap(vector<int>& nums)
{
    if (nums.size() < 2)
        return 0;

    int max = *max_element(nums.begin(), nums.end());
    int min = *min_element(nums.begin(), nums.end());

    double interval_length = double(max - min) / nums.size();

    vector<int> max_in_interval(nums.size(), INT_MIN);
    vector<int> min_in_interval(nums.size(), INT_MAX);

    for (auto &&each : nums)
    {
        size_t index = (each - min) / interval_length; // auto ceiling
        if (index == nums.size())    // in considering of float-point number round up
        {
            index = nums.size() - 1;
        }
        if (max_in_interval[index] < each)
        {
            max_in_interval[index] = each;
        }
        if (min_in_interval[index] > each)
        {
            min_in_interval[index] = each;
        }
    }

    int gap = 0;
    int max_in_previous_interval = max_in_interval[0];
    for (size_t i = 0; i < nums.size() - 1; ++i)
    {
        if (min_in_interval[i + 1] == INT_MAX)   // skip the empty interval
        {
            continue;
        }
        else
        {
            if (gap < min_in_interval[i + 1] - max_in_previous_interval)
            {
                gap = min_in_interval[i + 1] - max_in_previous_interval;
            }
            max_in_previous_interval = max_in_interval[i + 1];
        }
    }
    return gap;
}
