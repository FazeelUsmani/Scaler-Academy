#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll INF = 1ll << 60;
#define mem(dp, a) memset(dp, a, sizeof dp)
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repb(i, a, b) for (ll i = a; i >= b; i--)
#define f(n) for (ll i = 0; i < n; i++)
#define pb(x) push_back(x)

struct trie
{
    bool leaf;
    int cnt;
    trie *child[26];
};

trie *create()
{
    trie *temp = new trie();
    temp->leaf = false;
    temp->cnt = 0;
    mem(temp->child, NULL);
    return temp;
}

void add(trie *root, string s)
{
    rep(i, 0, s.length())
    {
        if (root->child[s[i] - 'a'] == NULL)
            root->child[s[i] - 'a'] = create();
        root = root->child[s[i] - 'a'];
    }
    root->leaf = true;
}

void print(trie *root, string ans)
{
    if (root->leaf == false)
    {
        rep(i, 0, 26)
        {
            if (root->child[i] != NULL)
            {
                ans = ans + (char)('a' + i);
                print(root->child[i], ans);
                ans = ans.substr(0, ans.length() - 1);
            }
        }
    }
    else
    {
        cout << ans << endl;
        root->leaf = false;
        print(root, ans);
    }
}

trie *root;

int main()
{
    int n;
    cin >> n;
    root = create();
    rep(i, 0, n)
    {
        string s;
        cin >> s;
        add(root, s);
    }
    print(root, "");
}