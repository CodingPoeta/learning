#include <mutex>

extern std::mutex mtx;

extern double dval;
extern int ival;

bool set_values(double dv, int iv) {
  std::lock_guard<std::mutex> lck(mtx);
  dval = dv;
  ival = iv;
  return true;
}
