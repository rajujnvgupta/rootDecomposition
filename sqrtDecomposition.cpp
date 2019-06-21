#include <iostream>
#include<math.h>

using namespace std;

int query(int *blocks, int *in, int l, int r, int rn)
{
    int ans = 0;
    ///left part to typical query
    while(l < r && l != 0 && l % rn != 0)
    {
        ans += in[l];
        l++;
    }

    ///middle part
    while(l + rn <= r)
    {
        int block_id = l/rn;
        ans += blocks[block_id];
        l += rn;
    }

    ///right part
    while(l <= r)
    {
        ans += in[l];
        l++;
    }

    return ans;
}

void update(int *blocks, int *in, int index, int val, int rn)
{
    int blocks_id = index / rn;
    blocks[blocks_id] += (val - in[index]);
    in[index] = val;
}

int main()
{
    int in[] = {1, 3, 5, 2, 7, 6, 3, 1, 4, 8};
    int n = sizeof(in)/ sizeof(int);
    int *blocks = new int[n+1];
    ///build sqrt decomposition
    int rn = sqrt(n);
    int block_id = -1;
    for(int i = 0; i < n; i++)
    {
        if(i % rn == 0)
        {
            block_id++;
        }
        blocks[block_id] += in[i];
    }

    for(int i = 0; i <=rn; i++)
        cout<<blocks[i]<<" ";

    int l, r;
    cin>>l>>r;
    int index = 2;
    int val = 15;
    update(blocks, in, index, val, rn);
    cout<<query(blocks, in, l, r, rn)<<" ";
    return 0;
}

