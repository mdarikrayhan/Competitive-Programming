// https://codeforces.com/problemset/problem/292/E

#include <iostream>
#include <optional>
#include <vector>

enum Cmd {
    CMD_COPY = 1,
    CMD_READ = 2,
};

class Node {
    int first_, last_;
    Node *left_ = nullptr, *right_ = nullptr;
    std::optional<int> val_;

public:
    Node(int first, int last):
        first_(first),
        last_(last)
    {
        if (last_ - first_ > 1) {
            const int mid = (first_ + last_) >> 1;
            left_ = new Node(first_, mid);
            right_ = new Node(mid, last_);
        }
    }

    int get(int pos) const {
        if (val_) {
            return *val_;
        }
        if (pos < left_->last_) {
            return left_->get(pos);
        } else {
            return right_->get(pos);
        }
    }

    void set(int first, int last, int val) {
        if (last_ <= first || last <= first_) {
            return;
        }
        if (first <= first_ && last_ <= last) {
            val_ = val;
            return;
        }
        if (val_) {
            left_->val_ = right_->val_ = val_;
            val_.reset();
        }
        left_->set(first, last, val);
        right_->set(first, last, val);
    }
};

class Handler {
    struct Query {
        int src_pos, dst_pos, len;
    };

    const std::vector<int>& src_vector_;
    const std::vector<int>& dst_vector_;

    Node root_;
    std::vector<Query> history_;

public:
    Handler(const std::vector<int>& src_vector, const std::vector<int>& dst_vector):
        root_(0, src_vector.size()),
        src_vector_(src_vector),
        dst_vector_(dst_vector)
    {
        root_.set(0, src_vector.size(), 0);
    }

    void copy(int src_pos, int dst_pos, int len) {
        Query query{src_pos, dst_pos, len};
        history_.push_back(query);
        root_.set(dst_pos, dst_pos + len, history_.size());
    }

    int read(int pos) const {
        const auto idx = root_.get(pos);
        if (idx == 0) {
            return dst_vector_[pos];
        }
        const auto& query = history_[idx - 1];
        return src_vector_[query.src_pos + (pos - query.dst_pos)];
    }
};

int main() {
    std::ios::sync_with_stdio(false);

    int size, query_count;
    std::cin >> size >> query_count;
    std::vector<int> src_vector(size), dst_vector(size);
    for (auto& val: src_vector) {
        std::cin >> val;
    }
    for (auto& val: dst_vector) {
        std::cin >> val;
    }

    Handler handler(src_vector, dst_vector);
    while (query_count-- > 0) {
        int cmd;
        std::cin >> cmd;
        if (cmd == CMD_COPY) {
            int src_pos, dst_pos, len;
            std::cin >> src_pos >> dst_pos >> len;
            handler.copy(src_pos - 1, dst_pos - 1, len);
        } else if (cmd == CMD_READ) {
            int pos;
            std::cin >> pos;
            std::cout << handler.read(pos - 1) << '\n';
        }
    }

    return EXIT_SUCCESS;
}
