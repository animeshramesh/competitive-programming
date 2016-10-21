void permute(string str, int i)
{   int n = str.size()-1;
    
    if (i == n)
        cout << str << endl;
    
    else
    {   for (int j = i; j<=n; j++)
        {   swap(str[i], str[j]);
            permute(str, j);
            swap(str[i], str[j]);
        }
    }
}

permute("abcd", 0);
