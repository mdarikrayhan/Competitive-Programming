 #include <bits/stdc++.h>
    #define pb push_back
    #define F first
    #define S second
    #define gcd __gcd
    #define int long long
    #define u unsigned
    #define err(x) cout << #x << ": " << x << endl;
    #define err2(x) cout << #x << ": " << x << ' ';
     
    using namespace std;
     
    typedef pair <int, int> pii;
    typedef vector <int> vi;
    typedef map <int, int> mi;
     
    const int MAX = 1e4 + 10;
    int n, m;
    set <int> row, col;
    char s[MAX][MAX], tmp[MAX][MAX];
     
    void Paint (){
    	for (int i = 0 ; i < n ; i++)
    		for (int j = 0 ; j < m ; j++)
    			tmp[i][j] = '.';
    }
     
    void Paint2 (int x1, int y1, int x2, int y2){
    	for (int i = x1 ; i <= x2 ; i++)
    		tmp[i][y1] = '#', tmp[i][y2] = '#';
    	for (int i = y1 ; i <= y2 ; i++)
    		tmp[x1][i] = '#', tmp[x2][i] = '#';
    }
     
    bool CheckEqual (){
    	for (int i = 0 ; i < n ; i++)
    		for (int j = 0 ; j < m ; j++)
    			if (s[i][j] != tmp[i][j])
    				return 0;
    	return 1;
    }
     
    bool CheckValid (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    	return ((x2 - x1 >= 2) && (y2 - y1 >= 2) && (x4 - x3 >= 2) && (y4 - y3 >= 2));
    }
     
    void DO (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    	if (CheckValid(x1, y1, x2, y2, x3, y3, x4, y4)){
    		Paint();
    		Paint2(x1, y1, x2, y2);
    		Paint2(x3, y3, x4, y4);
    		if (CheckEqual()){
    			cout << "YES" << endl;
    			cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
    			cout << x3 + 1 << " " << y3 + 1 << " " << x4 + 1 << " " << y4 + 1 << endl;
    			exit (0);
    		}
    	}
    }
     
    main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
    	cin >> n >> m;
    	for (int i = 0 ; i < n ; i++)
    		for (int j = 0 ; j < m ; j++)
    			cin >> s[i][j];
    	for (int i = 0 ; i < n ; i++){
    		for (int j = 0 ; j < m ; j++){
    			if (s[i][j] == '#' && s[i][j + 1] == '#' && s[i][j + 2] == '#')
    				row.insert(i);
    			if (s[i][j] == '#' && s[i + 1][j] == '#' && s[i + 2][j] == '#')
    				col.insert(j);
    		}
    	}
    	if (row.size() > 4)	row.erase(++++row.begin(), ----row.end());
    	if (col.size() > 4)	col.erase(++++col.begin(), ----col.end());
    	for (auto x1 : row)
    		for (auto y1 : col)
    			for (auto x2 : row)
    				for (auto y2: col)
    					for (auto x3 : row)
    						for (auto y3 : col)
    							for (auto x4 : row)
    								for (auto y4 : col)
    									DO(x1, y1, x2, y2, x3, y3, x4, y4);
    	return cout << "NO", 0;
	}