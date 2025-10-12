#include <bits/stdc++.h>
using namespace std;

struct Interval { unsigned long long s,e; string brand; };

string pad10(unsigned long long x) {
    string t = to_string(x);
    if (t.size() < 10) t = string(10 - t.size(), '0') + t;
    return t;
}
string pad6(int x) {
    string t = to_string(x);
    if (t.size() < 6) t = string(6 - t.size(), '0') + t;
    return t;
}

vector<string> obfuscateCardMetadata(int card_bin, vector<string> card_intervals) {
    const unsigned long long L = 0ULL, U = 9999999999ULL;
    vector<Interval> v;
    v.reserve(card_intervals.size());
    for (auto &ln : card_intervals) {
        size_t c1 = ln.find(','), c2 = ln.find(',', c1+1);
        unsigned long long a = stoull(ln.substr(0,c1));
        unsigned long long b = stoull(ln.substr(c1+1, c2-c1-1));
        string brand = ln.substr(c2+1);
        v.push_back({a,b,brand});
    }
    if (v.empty()) return {};

    sort(v.begin(), v.end(), [](const Interval &A, const Interval &B){
        if (A.s != B.s) return A.s < B.s;
        return A.e < B.e;
    });

    v.front().s = L;
    v.back().e  = U;

    // process with explicit splitting for containment/overlap
    deque<Interval> dq;
    for (auto cur : v) {
        if (dq.empty()) { dq.push_back(cur); continue; }
        while (!dq.empty()) {
            Interval top = dq.back();
            // disjoint to the right -> possibly fix gap then push cur
            if (cur.s > top.e + 1) {
                // fill gap by extending earlier (top) to cur.s-1
                dq.back().e = cur.s - 1;
                dq.push_back(cur);
                break;
            }
            // overlap or adjacent
            if (cur.s <= top.e) {
                if (top.brand == cur.brand) {
                    // same brand -> merge into top
                    dq.back().e = max(top.e, cur.e);
                    break;
                } else {
                    // different brands -> handle cases
                    if (cur.s >= top.s && cur.e <= top.e) {
                        // cur fully inside top -> split top into left, cur, right
                        unsigned long long leftS = top.s;
                        unsigned long long leftE = cur.s > 0 ? cur.s - 1 : 0;
                        unsigned long long rightS = cur.e + 1;
                        unsigned long long rightE = top.e;
                        dq.pop_back();
                        if (leftS <= leftE) dq.push_back({leftS,leftE,top.brand});
                        dq.push_back(cur);
                        if (rightS <= rightE) dq.push_back({rightS,rightE,top.brand});
                        break;
                    } else if (cur.s <= top.e && cur.e > top.e) {
                        // partial overlap where cur extends beyond top
                        // keep top up to cur.s-1, then cur will remain (potentially extend)
                        dq.back().e = (cur.s==0 ? 0 : cur.s - 1);
                        // continue the while to see if new cur overlaps earlier segments (rare)
                        // after shortening top, loop will continue and find either disjoint or merging
                        if (dq.back().s > dq.back().e) dq.pop_back(); // guard zero-length
                        // now re-evaluate against new back, but we should push cur next iteration of while:
                        if (dq.empty()) { dq.push_back(cur); break; }
                        // if still not placed, continue loop to compare with new back
                        continue;
                    } else {
                        // fallback (shouldn't happen) -> just push cur
                        dq.push_back(cur);
                        break;
                    }
                }
            } else {
                // cur starts after top.e but contiguous or adjacent handled earlier
                dq.push_back(cur);
                break;
            }
        } // end while
    } // end for

    // final merge adjacent same-brand (defensive)
    vector<Interval> out;
    for (auto &it : dq) {
        if (!out.empty() && out.back().brand == it.brand && it.s <= out.back().e + 1) {
            out.back().e = max(out.back().e, it.e);
        } else {
            out.push_back(it);
        }
    }

    string bin6 = pad6(card_bin);
    vector<string> result;
    result.reserve(out.size());
    for (auto &it : out) {
        result.push_back(bin6 + pad10(it.s) + "," + bin6 + pad10(it.e) + "," + it.brand);
    }
    return result;
}
