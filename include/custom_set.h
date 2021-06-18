//
// Created by jeounghui on 2021-06-18.
//

#ifndef PUZZLE_CUSTOM_SET_H
#define PUZZLE_CUSTOM_SET_H

#include <ext/pb_ds/assoc_container.hpp>

// much faster than unordered_set, https://codeforces.com/blog/entry/60737?
template<typename T>
using hash_set = __gnu_pbds::gp_hash_table<T,
    __gnu_pbds::null_type,
    std::hash<T>,
    std::equal_to<T>,
    __gnu_pbds::direct_mask_range_hashing<T>,
    __gnu_pbds::linear_probe_fn<>,
    __gnu_pbds::hash_standard_resize_policy<
        __gnu_pbds::hash_exponential_size_policy<>,
        __gnu_pbds::hash_load_check_resize_trigger<true>,
        true
    >
>;

// https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/HashMap.h
struct my_hash{
    const uint64_t C = int64_t(4e18 * acos(0)) | 71;
    int64_t operator () (int64_t x) const {
        return __builtin_bswap64(x*C);
    }
};

#endif //PUZZLE_CUSTOM_SET_H
