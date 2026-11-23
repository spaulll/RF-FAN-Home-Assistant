// Auto-generated from firmware codes — do not edit by hand.
// Regenerate with docs/gen_remote_sync_automation.py
#pragma once
#include <vector>
#include <cstring>

namespace rf_fan {

static const char* const kButtons[13] = {
    "OFF", "1", "2", "3", "4", "5", "ON", "Sleep", "HYP", "1H", "2H", "3H", "4H"};

// 39 signatures, 65 chars each; fans 1..3, buttons 0..12
static const char kS1_0[] = "SLSLLSSLSLLSLSSLLSSLLSSLSLSLLSSLSLLSSLLSSLLSLSSLSLSLSLSLSLLSSLLSS";
static const char kS1_1[] = "SLSLLSSLSLLSLSSLLSSLLSSLSLSLLSSLSLLSSLLSSLLSSLLSSLSLLSLSSLLSSLLSS";
static const char kS1_2[] = "SLSLLSSLSLLSLSSLLSSLLSSLSLSLLSSLSLLSSLLSLSLSLSLSSLLSLSSLLSSLLSSLS";
static const char kS1_3[] = "SLSLLSSLSLLSLSSLLSSLLSSLSLSLLSSLSLLSSLLSSLLSSLSLSLSLLSLSSLLSSLSLS";
static const char kS1_4[] = "SLSLLSSLSLLSLSSLLSSLLSSLSLSLLSSLSLLSSLLSSLSLLSLSSLLSSLSLSLLSSLSLS";
static const char kS1_5[] = "SLSLLSSLSLLSLSSLLSSLLSSLSLSLLSSLSLLSSLLSSLSLLSSLSLSLSLLSSLSLSLSLS";
static const char kS1_6[] = "SLSLLSSLSLLSLSSLLSSLLSSLSLSLLSSLSLLSSLLSLSLSLSSLSLLSLSLSLSSLLSSLS";
static const char kS1_7[] = "SLSLLSSLSLLSLSSLLSSLLSSLSLSLLSSLSLLSSLLSLSSLSLSLSLLSSLSLLSLSLSLSS";
static const char kS1_8[] = "SLSLLSSLSLLSLSSLLSSLLSSLSLSLLSSLSLLSSLLSLSLSSLSLSLSLLSLSLSLSSLSLS";
static const char kS1_9[] = "SLSLLSSLSLLSLSSLLSSLLSSLSLSLLSSLSLLSSLLSLSSLSLSLSLLSSLLSLSLSLSSLS";
static const char kS1_10[] = "SLSLLSSLSLLSLSSLLSSLLSSLSLSLLSSLSLLSSLLSSLSLSLLSSLSLLSSLSLSLSLSLS";
static const char kS1_11[] = "SLSLLSSLSLLSLSSLLSSLLSSLSLSLLSSLSLLSSLLSLSSLSLLSSLLSLSLLLSLSSLLLS";
static const char kS1_12[] = "SLSLLSSLSLLSLSSLLSSLLSSLSLSLLSSLSLLSSLLSLSSLSLLSSLLSSLLSLSLSSLLSS";
static const char kS2_0[] = "SLLSLSSLSLSLLSLSSLSLSLLSLSSLLSLSSLSLSLSLSLLSLSSLSLSLLSLSSLSLSLSLS";
static const char kS2_1[] = "SLLSLSSLSLSLLSLSSLSLSLLSLSSLLSLSSLSLSLSLSLLSSLLSSLLSSLSLSLLSSLSLS";
static const char kS2_2[] = "SLLSLSSLSLSLLSLSSLSLSLLSLSSLLSLSSLSLSLSLLSLSLSLSSLSLSLLSLSSLLSLSS";
static const char kS2_3[] = "SLLSLSSLSLSLLSLSSLSLSLLSLSSLLSLSSLSLSLSLSLLSSLSLSLSLLSSLSLSLLSLSS";
static const char kS2_4[] = "SLLSLSSLSLSLLSLSSLSLSLLSLSSLLSLSSLSLSLSLSLSLLSLSSLLSLSLSSLSLSLLSS";
static const char kS2_5[] = "SLLSLSSLSLSLLSLSSLSLSLLSLSSLLSLSSLSLSLSLSLSLLSSLSLSLSLSLSLLSLSLSS";
static const char kS2_6[] = "SLLSLSSLSLSLLSLSSLSLSLLSLSSLLSLSSLSLSLSLLSLSLSSLSLLSLSSLLSLSSLLSS";
static const char kS2_7[] = "SLLSLSSLSLSLLSLSSLSLSLLSLSSLLSLSSLSLSLSLLSSLSLSLSLLSLSSLLSSLLSLSS";
static const char kS2_8[] = "SLLSLSSLSLSLLSLSSLSLSLLSLSSLLSLSSLSLSLSLLSLSSLSLSLLSSLLSLSLSSLSLS";
static const char kS2_9[] = "SLLSLSSLSLSLLSLSSLSLSLLSLSSLLSLSSLSLSLSLLSLSSLLSSLSLLSLSLSSLLSLSS";
static const char kS2_10[] = "SLLSLSSLSLSLLSLSSLSLSLLSLSSLLSLSSLSLSLSLSLSLSLLSSLLSSLSLSLSLSLSLS";
static const char kS2_11[] = "SLLSLSSLSLSLLSLSSLSLSLLSLSSLLSLSSLSLSLSLLSSLSLLSSLSLSLLSLSLSSLLSS";
static const char kS2_12[] = "SLLSLSSLSLSLLSLSSLSLSLLSLSSLLSLSSLSLSLSLSLLSLSLSSLSLLSSLSLSLSLSLS";
static const char kS3_0[] = "SLSLSLSLLSSLSLLSLSSLSLSLLSSLSLLSSLLSSLLSSLLSLSSLSLLSSLSLSLLSSLLSS";
static const char kS3_1[] = "SLSLSLSLLSSLSLLSLSSLSLSLLSSLSLLSSLLSSLLSSLLSSLLSSLSLSLLSSLSLLSLSS";
static const char kS3_2[] = "SLSLSLSLLSSLSLLSLSSLSLSLLSSLSLLSSLLSSLLSLSLSLSLSSLSLLSSLLSSLLSSLS";
static const char kS3_3[] = "SLSLSLSLLSSLSLLSLSSLSLSLLSSLSLLSSLLSSLLSSLLSSLSLSLLSLSLSSLLSSLSLS";
static const char kS3_4[] = "SLSLSLSLLSSLSLLSLSSLSLSLLSSLSLLSSLLSSLLSSLSLLSLSSLSLSLSLSLLSSLSLS";
static const char kS3_5[] = "SLSLSLSLLSSLSLLSLSSLSLSLLSSLSLLSSLLSSLLSSLSLLSSLSLLSSLLSSLSLSLSLS";
static const char kS3_6[] = "SLSLSLSLLSSLSLLSLSSLSLSLLSSLSLLSSLLSSLLSLSLSLSSLSLSLLSLSLSSLLSSLS";
static const char kS3_7[] = "SLSLSLSLLSSLSLLSLSSLSLSLLSSLSLLSSLLSSLLSLSSLSLSLSLSLLSLSLSLSSLSLS";
static const char kS3_8[] = "SLSLSLSLLSSLSLLSLSSLSLSLLSSLSLLSSLLSSLLSLSLSSLSLSLLSLSSLLSLSSLLSS";
static const char kS3_9[] = "SLSLSLSLLSSLSLLSLSSLSLSLLSSLSLLSSLLSSLLSLSLSSLLSSLLSSLSLLSLSLSSLS";
static const char kS3_10[] = "SLSLSLSLLSSLSLLSLSSLSLSLLSSLSLLSSLLSSLLSSLSLSLLSSLSLSLLSSLLSLSLSS";
static const char kS3_11[] = "SLSLSLSLLSSLSLLSLSSLSLSLLSSLSLLSSLLSSLLSLSSLSLLSSLSLLSSLLSLSSLSLS";
static const char kS3_12[] = "SLSLSLSLLSSLSLLSLSSLSLSLLSSLSLLSSLLSSLLSSLLSLSLSSLLSLSLSSLLSLSLSS";

struct CodeEntry { const char* sig; int fan; int key; };

static const CodeEntry kCodes[] = {
    { kS1_0, 1, 0 },
    { kS1_1, 1, 1 },
    { kS1_2, 1, 2 },
    { kS1_3, 1, 3 },
    { kS1_4, 1, 4 },
    { kS1_5, 1, 5 },
    { kS1_6, 1, 6 },
    { kS1_7, 1, 7 },
    { kS1_8, 1, 8 },
    { kS1_9, 1, 9 },
    { kS1_10, 1, 10 },
    { kS1_11, 1, 11 },
    { kS1_12, 1, 12 },
    { kS2_0, 2, 0 },
    { kS2_1, 2, 1 },
    { kS2_2, 2, 2 },
    { kS2_3, 2, 3 },
    { kS2_4, 2, 4 },
    { kS2_5, 2, 5 },
    { kS2_6, 2, 6 },
    { kS2_7, 2, 7 },
    { kS2_8, 2, 8 },
    { kS2_9, 2, 9 },
    { kS2_10, 2, 10 },
    { kS2_11, 2, 11 },
    { kS2_12, 2, 12 },
    { kS3_0, 3, 0 },
    { kS3_1, 3, 1 },
    { kS3_2, 3, 2 },
    { kS3_3, 3, 3 },
    { kS3_4, 3, 4 },
    { kS3_5, 3, 5 },
    { kS3_6, 3, 6 },
    { kS3_7, 3, 7 },
    { kS3_8, 3, 8 },
    { kS3_9, 3, 9 },
    { kS3_10, 3, 10 },
    { kS3_11, 3, 11 },
    { kS3_12, 3, 12 },
};

static constexpr size_t kCodeLen = 65;
static constexpr size_t kMaxDiff = 4;

static inline int hamming(const char* a, const char* b, size_t n) {
  int d = 0;
  for (size_t i = 0; i < n; i++) if (a[i] != b[i]) d++;
  return d;
}

// Decode raw RX pulses (µs, alternating mark/space) into S/L string.
template<typename T>
static inline void normalize(const std::vector<T>& x, char* out, size_t max) {
  size_t n = x.size();
  if (n > max) n = max;
  for (size_t i = 0; i < n; i++) {
    T v = x[i];
    if (v < 0) v = -v;
    out[i] = (v >= 450) ? 'L' : 'S';
  }
  out[n] = '\0';
}

template<typename T>
static inline bool rf_match(const std::vector<T>& x, int& fan, int& button) {
  char buf[80];
  size_t n = x.size();
  if (n < 63 || n > 70) return false;
  normalize(x, buf, sizeof(buf) - 1);
  size_t len = strlen(buf);
  // candidate alignments (drop trailing / leading)
  struct { const char* p; size_t l; } cand[2];
  size_t nc = 0;
  if (len >= kCodeLen) { cand[nc].p = buf; cand[nc].l = kCodeLen; nc++; }
  if (len >= kCodeLen + 1) { cand[nc].p = buf + 1; cand[nc].l = kCodeLen; nc++; }
  for (size_t c = 0; c < nc; c++) {
    for (size_t i = 0; i < 39; i++) {
      if (hamming(cand[c].p, kCodes[i].sig, kCodeLen) <= kMaxDiff) {
        fan = kCodes[i].fan;
        button = kCodes[i].key;
        return true;
      }
    }
  }
  return false;
}

}  // namespace rf_fan
