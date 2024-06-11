class Solution {
public:
    using info = pair<int, int>; // (x, freq)
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        const int n1 = arr1.size(), n2 = arr2.size();
        int a2i[1001];

        // Initialize a2i with n2 (indicating elements not in arr2)
        fill(a2i, end(a2i), n2);
        for (int i = 0; i < n2; i++) 
            a2i[arr2[i]] = i;

        // Counting sort uses 2 containers bucket & freqN2
        info bucket[1001];
        int freqN2[1001] = {0};
        fill(bucket, end(bucket), info(-1, 0)); // fill  with pair {-1, 0}
        
        // Process arr1 to fill bucket and freqN2
        for (int x : arr1) {
            int i = a2i[x];
            if (i == n2) 
                freqN2[x]++;
             else {
                bucket[i].first = x;
                bucket[i].second++;
            }
        }

        int cnt = 0;
        // Place elements from bucket according to the order in arr2
        for (short i = 0; i < n2; i++) {
            auto& [x, f] = bucket[i];
            if (f == 0) continue;
            fill(arr1.begin()+cnt, arr1.begin()+cnt+f, x);
            cnt+=f;
        }

        // Place elements not in arr2 sorted in ascending order
        for (int x = 0; x <= 1000; x++) {
            int f = freqN2[x];
            if (f == 0) continue;
            fill(arr1.begin()+cnt, arr1.begin()+cnt+f, x);
            cnt+=f;
        }

        return arr1;
    }
};




auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();