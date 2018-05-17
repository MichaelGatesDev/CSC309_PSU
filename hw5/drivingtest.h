/* http://www.speedyroadtestny.com/wp-content/uploads/2015/11/Road-Test-Evaluation-Form.jpg */
#define TOO_FAR_FROM_CURB           0x1   // 000000001
#define UNABLE_TO_PARK_PROPERLY     0x2   // 000000010
#define FAILURE_TO_CHECK_BLINDSPOTS 0x4   // 000000100
#define POOR_JUDGEMENT_SPEEDING     0x8   // 000001000
#define POOR_JUDGEMENT_TURNING      0x10  // 000010000
#define POOR_JUDGEMENT_STOPPING     0x20  // 000100000
#define POOR_JUDGEMENT_SIGNALING    0x40  // 001000000
#define FAILURE_TO_KEEP_RIGHT       0x80  // 010000000
#define IMPROPER_LANE               0x100 // 100000000
#define TOTAL_INFRACTIONS           9

struct testResult {
    short result;
    struct testResult *next;
};

struct testResult *generateTests(int size);
short generateRandomResult();
void printTestResults(struct testResult *listHead);
void printTestResult(short n);
int countBitsSet(short n);

void printBinary(unsigned n);
