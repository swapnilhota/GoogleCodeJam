/*
We have a list of integers X1,X2,…,XN. We would like them to be in strictly increasing order, but unfortunately, we cannot reorder them. 
This means that usual sorting algorithms will not work. Our only option is to change them by appending digits 0 through 9 to their right (in base 10). 
For example, if one of the integers is 10, you can turn it into 100 or 109 with a single append operation, or into 1034 with two operations (as seen in the image below).
Given the current list, what is the minimum number of single digit append operations that are necessary for the list to be in strictly increasing order?
For example, if the list is 100,7,10, we can use 4 total operations to make it into a sorted list, as the following image shows.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case is described in two lines. 
The first line of a test case contains a single integer N, the number of integers in the list. The second line contains N integers X1,X2,…,XN, the members of the list.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum number 
of single digit append operations needed for the list to be in strictly increasing order.

Limits
Time limit: 10 seconds.
Memory limit: 1 GB.
1≤T≤100.
Test Set 1 (Visible Verdict)
2≤N≤3.
1≤Xi≤100, for all i.
Test Set 2 (Visible Verdict)
2≤N≤100.
1≤Xi≤109, for all i.
*/


#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int caseNo = 0;

    while(t--)
    {
        int n;
        cin >> n;

        long long a[n];

        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }

        long long ans = 0;

        for(int i=1; i<n; i++)
        {
            if(a[i]>a[i-1])
            {
                continue;
            }

            if(a[i]==a[i-1])
            {
                ans++;
                string currS = to_string(a[i]);
                a[i] = stoll(currS+"0");
                continue;
            }

            string currS = to_string(a[i]);
            string prevS = to_string(a[i-1]);

            int currLen = to_string(a[i]).length();
            int prevLen = to_string(a[i-1]).length();

            if(currLen==prevLen)
            {
                ans++;
                a[i] = stoll(currS+"0");
                continue;
            }

            if(currS[0]>prevS[0])
            {
                ans += (prevLen-currLen);
                for(int k=0; k<(prevLen-currLen)-1; k++)
                {
                    currS += "0";
                }
                currS += "0";
                a[i] = stoll(currS);
                continue;
            }

            if(currS[0]<prevS[0])
            {
                ans += (prevLen-currLen)+1;
                for(int k=0; k<(prevLen-currLen); k++)
                {
                    currS += "0";
                }
                currS += "0";
                a[i] = stoll(currS);
                continue;
            }

            int cnt=0;
            int flag=0;

            for(int j=0; j<currS.length(); j++)
            {
                if(currS[j]==prevS[j])
                {
                    cnt++;
                    continue;
                }
                if(currS[j]<prevS[j])
                {
                    break;
                }
                if(currS[j]>prevS[j])
                {
                    flag=1;
                    break;
                }
            }

            if(flag==1)
            {
                ans += (prevLen-currLen);
                for(int k=0; k<(prevLen-currLen)-1; k++)
                {
                    currS += "0";
                }
                currS += "0";
                a[i] = stoll(currS);
            }
            else
            {
                if(cnt==currLen)
                {
                    int temp = prevLen-currLen;
                    long long temp2 = (long long)pow(10, temp)-1;
                    string s = prevS.substr(currLen);
                    long long num = stoll(s);
                    if(num<temp2)
                    {
                        ans += (prevLen-currLen);
                        string str = to_string(num+1);
                        if(str.length()==(prevLen-currLen))
                        {
                            currS += to_string(num+1);
                        }
                        else
                        {
                            int m = (prevLen-currLen)-str.length();
                            for(int p=0; p<m; p++)
                            {
                                str = "0" + str;
                            }
                            currS += str;
                        }
                        a[i] = stoll(currS);
                    }
                    else
                    {
                        ans += (prevLen-currLen)+1;
                        for(int k=0; k<(prevLen-currLen); k++)
                        {
                            currS += "0";
                        }
                        currS += "0";
                        a[i] = stoll(currS);
                    }
                }
                else
                {
                    ans += (prevLen-currLen)+1;
                    for(int k=0; k<(prevLen-currLen); k++)
                    {
                        currS += "0";
                    }
                    currS += "0";
                    a[i] = stoll(currS);
                }
            }


        }

        caseNo++;
        cout << "Case #" << caseNo << ':' << " " << ans << endl;
        for(int i=0; i<n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
