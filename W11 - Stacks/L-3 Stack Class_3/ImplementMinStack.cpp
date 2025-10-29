#include <iostream>
#include <utility>
using namespace std;

class MinStack
{
    public:
        vector<pair<int, int>> st;

        void push(int val)
        {
            if (st.empty())
            {
                // IT MEAN, I AM INSERTING FIRST ELEMENT
                pair<int, int> p;
                p.first = val;
                p.second = val;
                st.push_back(p);
            }
            else
            {
                pair<int, int> p;
                p.first = val;
                int lastMin = st.back().second;
                p.second = min(lastMin, val);
                st.push_back(p);

            }
        }

        void pop()
        {
            st.pop_back();
        }
        
        int top()
        {
            pair<int, int> rightMostPair = st.back();
            return rightMostPair.first;
        }
        
        int getMin()
        {
            pair<int, int> rightMostPair = st.back();
            return rightMostPair.second;
        }

        void print()
        {
            for (auto p: st)
            {
                cout << p.first << " ";
            }
            cout << endl;
        }
};


int main()
{
    MinStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    st.pop();
    st.print();

    int topElem = st.top();
    cout << "TOP ELEMENT OF STACK IS: " << topElem << endl;

    int minElem = st.getMin();
    cout << "MINUM ELEMENT OF STACK IS: " << minElem << endl;
    return 0;
}