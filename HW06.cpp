#include <iostream>
using namespace std;
class Ranking{

private:
    int data[1000];
    int size;
    int temp[1000];

public:
    Ranking(int n){
      size = n;
    }

    void inputData(){
        for(int i=0;i<size;i++){
            cin>>data[i];
        }
    }

    int binarySearch(int key){
      // Sequential
       // int i = 0;
       // while (i<size){
         //     if (key == data[i])
             //     return (i+1);
          //    else
              //    i = i+1;
     //   }
       // return (NULL);

      //Binary Search
        int l = 0;
        int r = size-1;
        int m;
      
        m = (l+r)/2;
        while (l <= r){

              if (key == data[m])
                  return (m+1);
              else{
                  if (key > data[m])
                      r = m-1;
                  else
                      l = m+1;
              }
            m = (l+r)/2;

        }
      return (NULL);
    }

    void merge(int left, int mid, int right){
	      int l_end = mid-1;
        int tt_p = left;
        int ne = right-left+1;

        while ((left <= l_end) && (mid <= right)){
              if (data[left] >= data[mid]){
                  temp[tt_p] = data[left];
                  tt_p = tt_p+1;
                  left = left+1;
                }

              else{
                  temp[tt_p] = data[mid];
                  tt_p = tt_p+1;
                  mid = mid+1;
              }
        }

        while (left <= l_end){
              temp[tt_p] = data[left];
              left = left+1;
              tt_p = tt_p+1;
        }
        while (mid <= right){
              temp[tt_p] = data[mid];
              mid = mid+1;
              tt_p = tt_p+1;
        }

        for (int a=0; a<ne; a++){
            data[right] = temp[right];
            right = right-1;
        }
    }

    void mergeSort(int left, int right){
        int m1;

        if (left < right){
            m1 = (right+left)/2;
          
            mergeSort(left, m1);
            mergeSort(m1+1, right);

            merge(left, m1+1, right);
        }
	}

    int show(int index){
        return data[index-1];
    }
};
