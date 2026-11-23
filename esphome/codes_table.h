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
static constexpr int kMaxEdit = 7;

static int g_dp[72][72];  // shared scratch (single-threaded)

static inline int edit_dist(const char* a, size_t n, const char* b, size_t m, int cap) {
  if (n > 71) n = 71;
  if (m > 71) m = 71;
  for (size_t i = 0; i <= n; i++) g_dp[i][0] = (int)i;
  for (size_t j = 0; j <= m; j++) g_dp[0][j] = (int)j;
  for (size_t i = 1; i <= n; i++) {
    int row_min = cap + 1;
    for (size_t j = 1; j <= m; j++) {
      int cost = (a[i-1] == b[j-1]) ? 0 : 1;
      int v = g_dp[i-1][j-1] + cost;
      if (g_dp[i-1][j] + 1 < v) v = g_dp[i-1][j] + 1;
      if (g_dp[i][j-1] + 1 < v) v = g_dp[i][j-1] + 1;
      g_dp[i][j] = v;
      if (v < row_min) row_min = v;
    }
    if (row_min > cap) return cap + 1;  // early bail
  }
  return g_dp[n][m];
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
  if (n < 62 || n > 72) return false;
  normalize(x, buf, sizeof(buf) - 1);
  size_t len = strlen(buf);
  int best = kMaxEdit;
  int best_i = -1;
  // try raw and shifted (drop leading pulse) alignments
  for (int shift = 0; shift <= 1; shift++) {
    if (len < kCodeLen + (size_t)shift) continue;
    const char* p = buf + shift;
    for (size_t i = 0; i < 39; i++) {
      int d = edit_dist(p, len - shift, kCodes[i].sig, kCodeLen, best);
      if (d < best) { best = d; best_i = (int)i; }
    }
  }
  if (best_i < 0) return false;
  fan = kCodes[best_i].fan;
  button = kCodes[best_i].key;
  return true;
}

// ---- burst vote aggregator ----
namespace {
  uint32_t s_last_frame = 0;
  uint32_t s_win_start = 0;
  int s_votes[3][13] = {};
  int s_best_fan = -1, s_best_btn = -1, s_best_cnt = 0;
}

template<typename T>
static inline void rf_observe(const std::vector<T>& x) {
  uint32_t now = millis();
  bool open = (s_win_start != 0) && (now - s_win_start <= 300);
  if (!open) {
    std::memset(s_votes, 0, sizeof(s_votes));
    s_win_start = now; s_best_cnt = 0; s_best_fan = -1; s_best_btn = -1;
  }
  int f, b;
  if (!rf_match(x, f, b)) return;
  s_votes[f - 1][b]++;
  if (s_votes[f - 1][b] > s_best_cnt) {
    s_best_cnt = s_votes[f - 1][b]; s_best_fan = f; s_best_btn = b;
  }
  s_last_frame = now;
}

static inline bool rf_pending() { return s_best_cnt > 0 && s_last_frame != 0; }

static inline bool rf_ready(uint32_t now) { return s_best_cnt > 0 && (now - s_last_frame >= 200); }

static inline void rf_take(int& fan, int& btn) {
  fan = s_best_fan; btn = s_best_btn;
  s_best_cnt = 0; s_best_fan = -1; s_best_btn = -1; s_win_start = 0; s_last_frame = 0;
}

}  // namespace rf_fan
