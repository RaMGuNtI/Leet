class ProductOfNumbers {
public:
    vector<int> stream;

    ProductOfNumbers() {
        stream.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            stream.clear();
            stream.push_back(1);
        } else {
            stream.push_back(stream.back() * num);
        }
    }

    int getProduct(int k) {
        int n = stream.size();

        if (k >= n) return 0;

        return stream[n - 1] / stream[n - k - 1];
    }
};