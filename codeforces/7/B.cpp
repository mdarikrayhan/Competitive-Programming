// LUOGU_RID: 159960045
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
typedef long long i64;

static constexpr int INF = 0x3f3f3f3f;

#ifdef NULL
#undef NULL
#endif

enum Error {
    NULL,
    ILLEGAL_ERASE_ARGUMENT,
};

struct AllocBlock {
    int start, len;

    AllocBlock(int start = 0, int len = 1)
        : start(start)
        , len(len)
    {
    }

    bool operator<(const AllocBlock& other) const
    {
        return tie(start, len) < tie(other.start, other.len);
    }

    bool operator==(const AllocBlock& other) const
    {
        return other.len == len && other.start == start;
    }

    int stop() const { return start + len - 1; }
};

struct Memory {
    int size, alloc_max;
    map<int, AllocBlock> allocated;
    vector<AllocBlock> alloc_order;

    Memory(int size = 0)
        : size(size)
        , alloc_max(-1)
        , allocated { { -1, { -1 } }, { INF, { size } } }
        , alloc_order { -1, size }
    {
    }

    unsigned alloc(int len)
    {
        if (len > size)
            return Error::NULL;

        int alloc_start = -1;

        for (auto it = alloc_order.begin(); it != alloc_order.end() - 1; ++it) {
            // auto idx = it - alloc_order.begin();
            auto block = *it;

            if (block.stop() + len < (it + 1)->start) {
                alloc_start = block.stop() + 1;
                break;
            }
        }

        if (alloc_start == -1)
            return Error::NULL;

        auto new_mem = AllocBlock { alloc_start, len };

        allocated[++alloc_max] = new_mem;
        alloc_order.insert(lower_bound(alloc_order.begin(), alloc_order.end(), new_mem), new_mem);

        return alloc_max + 1;
    }

    int erase(int alloc_idx)
    {
        --alloc_idx;

        if (alloc_idx < 0 || alloc_idx > alloc_max || !allocated.count(alloc_idx))
            return Error::ILLEGAL_ERASE_ARGUMENT;

        alloc_order.erase(lower_bound(alloc_order.begin(), alloc_order.end(), allocated[alloc_idx]));
        allocated.erase(alloc_idx);

        return 0;
    }

    void tidy(int idx = -1)
    {
        auto nxt_idx = next(idx);

        if (nxt_idx == INF || nxt_idx < 0)
            return;

        lower_bound(alloc_order.begin(), alloc_order.end(), allocated[nxt_idx])->start = allocated[idx].stop() + 1;
        allocated[nxt_idx].start = allocated[idx].stop() + 1;

        tidy(nxt_idx);
    }

private:
    int next(int idx)
    {
        int min_idx = INF;
        AllocBlock res = allocated[INF];

        for (const auto& alloc_block : allocated) {
            auto i = alloc_block.first;
            auto block = alloc_block.second;

            if (block.start > allocated[idx].stop() && block < res) {
                res = block;
                min_idx = i;
            }
        }

        return min_idx;
    }
};

int main()
{
    int t, m;
    cin >> t >> m;
    Memory mem(m);

    while (t-- > 0) {
        string cmd;
        cin >> cmd;

        if (cmd == "alloc") {
            int len;
            cin >> len;

            int res = mem.alloc(len);

            if (res == Error::NULL)
                puts("NULL");
            else
                cout << res << '\n';
        } else if (cmd == "erase") {
            int idx;
            cin >> idx;

            if (mem.erase(idx) == Error::ILLEGAL_ERASE_ARGUMENT)
                puts("ILLEGAL_ERASE_ARGUMENT");
        } else if (cmd == "defragment")
            mem.tidy();

        for (const auto& alloc_block : mem.allocated) {
            if (alloc_block.first >= 0 && alloc_block.first < INF)
                fprintf(stderr, "[%d] = [%d, %d)\n", alloc_block.first, alloc_block.second.start, alloc_block.second.stop() + 1);
        }

        fputc('\n', stderr);
    }

    return 0;
}
		 	 	     	 		 	  						  	  	