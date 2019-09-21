#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }


  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }
  void sift_down(int i){
  	int min_index= i;
  	int l = 2*i + 1;
  	if(l <= (data_.size() - 1) && data_[l] < data_[min_index]){
  		min_index = l;
	  }
	int r = 2*i + 2;
	if( r <= data_.size() - 1 && data_[r] < data_[min_index]){
		min_index = r;
	}
	if(min_index != i){
		swap(data_[i],data_[min_index]);
		swaps_.push_back(make_pair(i,min_index));
		sift_down(min_index);
	}
  }
  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    int last_index = data_.size() - 1;
	int n = (last_index-1)/2;
	for(int i = n ; i >= 0 ; i--){
		sift_down(i);
	}	
	}	

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
