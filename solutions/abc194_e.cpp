#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  
  int N, M;
  cin >> N >> M;
  vector<int> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];

  set<int> st;
  map<int, int> counts;

  for(int i = 0; i <= N; i++) st.insert(i);
  for(int i = 0; i < M - 1; i++){
    counts[a[i]]++;
    st.erase(a[i]);
  }

  vector<int> mexList;
  for(int i = M - 1; i < N; i++){
    counts[a[i]]++;
    st.erase(a[i]);

    mexList.push_back(*st.begin());

    counts[a[i - M + 1]]--;
    if(counts[a[i - M + 1]] == 0) st.insert(a[i - M + 1]);
  }
  cout << *min_element(mexList.begin(), mexList.end()) << endl;
}
