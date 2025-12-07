#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>

using namespace std;

struct Player {
    string username;
    string password;
    string nickname;
    int score;
    int balance;
};

const int MAX_ACCOUNTS = 100;

Player accounts[MAX_ACCOUNTS];
int accountCount = 0;

Player currentUser;

// fungsi untuk ngitung akun
void loadAccounts() {
    ifstream file("accounts.txt");
    if (!file) {
        return;
    }

    accountCount = 0;
    while (accountCount < MAX_ACCOUNTS &&
           file >> accounts[accountCount].username
                >> accounts[accountCount].password
                >> accounts[accountCount].nickname
                >> accounts[accountCount].score
                >> accounts[accountCount].balance) {
        accountCount++;
    }

    file.close();
}

// nyimpen perubahan akun terbaru secara permanen
void saveAccounts() {
    ofstream file("accounts.txt");
    for (int i = 0; i < accountCount; i++) {
        file << accounts[i].username << '\n'
             << accounts[i].password << '\n'
             << accounts[i].nickname << '\n'
             << accounts[i].score << '\n'
             << accounts[i].balance << '\n';
    }
    file.close();
}

// memeriksa kapasitas dan keberadaan yang sudah ada
void registerAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        cout << "Kapasitas akun penuh.\n";
        return;
    }

    Player newAcc;

    cout << "\n==== REGISTER ====\n";
    cout << "Buat username   : ";
    cin  >> newAcc.username;

    // Cek username duplikat
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].username == newAcc.username) {
            cout << "Username sudah dipakai.\n";
            return;
        }
    }

    cout << "Buat password   : ";
    cin  >> newAcc.password;

    cout << "Nama panggilan  : ";
    cin  >> newAcc.nickname;

    newAcc.score   = 0;
    newAcc.balance = 100;

    accounts[accountCount] = newAcc;
    accountCount++;

    saveAccounts();

    cout << "\nAkun berhasil dibuat!\n";
}

bool loginAccount() {
    string u, p;

    cout << "\n==== LOGIN ====\n";
    cout << "Username : ";
    cin  >> u;
    cout << "Password : ";
    cin  >> p;

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].username == u &&
            accounts[i].password == p) {
            currentUser = accounts[i];
            cout << "\nLogin berhasil! Halo, " << currentUser.nickname << "!\n";
            return true;
        }
    }

    cout << "Username atau password salah.\n";
    return false;
}

// update data
void updateCurrentUser() {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].username == currentUser.username) {
            accounts[i] = currentUser;
            break;
        }
    }
    saveAccounts();
}

// pengetahuan umum
void playPopQuiz() {
    char confirm;
    char jawab = 'z';
    int  tempScore = 0;

    cout << "\n=== POP QUIZ ===\n";
    cout << "Selamat datang di Pop Quiz!\n"
            "Apakah kamu siap untuk menjawab pertanyaan?\n"
            "(y/n) > ";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        cout << "\n\n\n\nBaiklah kita mulai!\n\n\n\n";

        cout << "Pertanyaan 1\n";
        cout << "Kapan End Of Service dari Windows 10?\n"
                "A. 14 Oktober 2025\tB. 17 Oktober 2025\n"
                "C. 30 September 2025\tD. 12 Oktober 2025\n> ";
        cin >> jawab;

        if ((jawab > 'd' && jawab > 'D') || !isalpha(jawab)) {
            cout << "Maaf tidak ada di pilihan.\nTetap dianggap salah ;-;";
        } else if (jawab == 'a' || jawab == 'A') {
            cout << "Benar!\nEnd of Service Windows 10 berakhir pada tanggal 14 Oktober 2025!";
            currentUser.score += 10;
            tempScore += 10;
        } else {
            cout << "Sayangnya bukan...\nEnd of Service Windows 10 berakhir pada tanggal 14 Oktober 2025.";
        }

        cout << "\n\n\n\nPertanyaan 2\n";
        cout << "Stasiun yang dekat dengan terminal Bungurasih adalah...\n"
                "A. Stasiun Wonokromo\tB. Stasiun Gedangan\n"
                "C. Stasiun Waru\t\tD. Stasiun Kertomenanggal\n> ";
        cin >> jawab;

        if ((jawab > 'd' && jawab > 'D') || !isalpha(jawab)) {
            cout << "Maaf tidak ada di pilihan.\nTetap dianggap salah ;-;";
        } else if (jawab == 'c' || jawab == 'C') {
            cout << "Benar!\nStasiun Waru adalah stasiun paling dekat dengan Terminal Bungurasih!";
            currentUser.score += 10;
            tempScore += 10;
        } else {
            cout << "Sayangnya bukan...\nStasiun Waru adalah stasiun paling dekat dengan Terminal Bungurasih.";
        }

        cout << "\n\n\n\nPertanyaan 3\n";
        cout << "Manakah makanan berikut yang khas dari Surabaya?\n"
                "A. Gudeg\tB. Pecel Semanggi\n"
                "C. Strudel Apel\tD. Pecel lele\n> ";
        cin >> jawab;

        if ((jawab > 'd' && jawab > 'D') || !isalpha(jawab)) {
            cout << "Maaf tidak ada di pilihan.\nTetap dianggap salah ;-;";
        } else if (jawab == 'b' || jawab == 'B') {
            cout << "Benar!\nPecel Semanggi adalah makanan khas dari Surabaya!";
            currentUser.score += 10;
            tempScore += 10;
        } else {
            cout << "Sayangnya bukan...\nYang benar adalah pecel semanggi.\nPecel Semanggi adalah makanan khas dari Surabaya.";
        }

        cout << "\n\n\n\nPertanyaan 4\n";
        cout << "Kapan hari guru nasional?\n"
                "A. 17 Agustus\tB. 25 November\n"
                "C. 1 Juni\tD. 22 Oktober\n> ";
        cin >> jawab;

        if ((jawab > 'd' && jawab > 'D') || !isalpha(jawab)) {
            cout << "Maaf tidak ada di pilihan.\nTetap dianggap salah ;-;";
        } else if (jawab == 'b' || jawab == 'B') {
            cout << "Benar!\nTanggal 25 November adalah hari guru nasional!";
            currentUser.score += 10;
            tempScore += 10;
        } else {
            cout << "Sayangnya bukan...\nTanggal 25 November adalah hari guru nasional.";
        }

        cout << "\n\n\n\nPertanyaan 5\n";
        cout << "20 5 18 21 19\n";
        cout << "A1Z26!\n"
                "A. Makan\tB. Pecel\n"
                "C. Terus\tD. Tidur\n> ";
        cin >> jawab;

        if ((jawab > 'd' && jawab > 'D') || !isalpha(jawab)) {
            cout << "Maaf tidak ada di pilihan.\nTetap dianggap salah ;-;";
        } else if (jawab == 'c' || jawab == 'C') {
            cout << "Benar!\nJawabannya adalah: Terus!";
            currentUser.score += 10;
            tempScore += 10;
        } else {
            cout << "Sayangnya bukan...\nA1Z26 adalah maksud dari urutan huruf (A=1, B=2, dst...).\n"
                    "Maka jawabannya adalah: Terus.";
        }

        cout << "\n\n\n\n=-=-=-=-=-=-=-=\n";
        cout << " Quiz berakhir!\n";
        cout << "=-=-=-=-=-=-=-=\n";
        cout << "\nSkor akhirmu adalah: " << tempScore << "!";
        updateCurrentUser();
        cout << "\nTerima kasih telah bermain! :D";
        cout << "\n**Tekan enter untuk keluar**\n";
        cin.ignore();
        cin.get();
        cout << "\n\n\n\n";
    } else if (confirm == 'n' || confirm == 'N') {
        cout << "Mungkin mental tidak siap, tapi tidak apa apa :)";
    }
}

// judi
void playGamble() {
    srand(static_cast<unsigned int>(time(0)));

    string mainLagi;
    do {
        int tebakan = 0;

        cout << "\n=== GAME TEBAK ANGKA RANDOM 1-10 ===\n";

        do {
            cout << "Masukkan Lotre (1-10): ";
            cin  >> tebakan;
            if (tebakan < 1 || tebakan > 10) {
                cout << "Silahkan pilih angka antara 1 sampai 10.\n";
            }
        } while (tebakan < 1 || tebakan > 10);

        int angkaRandom = (rand() % 10) + 1;
        cout << "Angka Jackpot: " << angkaRandom << '\n';

        if (tebakan == angkaRandom) {
            cout << "SELAMAT! JACKPOT\nJACKPOT ASELOLE\n";
        } else {
            cout << "ZONK!! RUNGKAD.\nYAHAHAHAHA RUNGKAD ZONK MAMPUS\n";
        }

        cout << "MAU MAIN LAGI? (YA/TIDAK): ";
        cin  >> mainLagi;
    } while (mainLagi == "ya" || mainLagi == "Ya" || mainLagi == "YA" || mainLagi == "yA");
}

// slow mengetik
void slowPrint(string text, int speed) {
    for (int i = 0; i < (int)text.size(); i++) {
        cout << text[i];
        cout.flush();

        for (int j = 0; j < speed * 50000; j++) {
        }
    }
}

void playHalu() {
    int choice;
    int r, r2;
    string name = currentUser.nickname;

    cout << "\n============= PLAY HALU =============\n";
    slowPrint("Choose your halu-character, " + name + "...\n\n", 400);

    cout << "1. Kenji  - Rival to Lovers\n";
    cout << "2. Leo    - Soft & Clingy (BL)\n";
    cout << "3. Kurama - The Nine-Tails\n";
    cout << "Your choice: ";
    cin >> choice;
    cout << '\n';

    if (choice == 1) {
        slowPrint("Kenji: \"Tch... kamu lagi, " + name + ".\"\n\n", 400);
        cout << "1. \"Kangen aja.\"\n";
        cout << "2. \"Mau ngalahin kamu.\"\n";
        cout << "Choice: ";
        cin >> r;
        cout << '\n';

        if (r == 1) {
            slowPrint("Kenji: \"Jangan tiba-tiba hilang lagi.\"\n", 400);
            cout << "1. \"Oke, bakal kabarin.\"\n";
            cout << "2. \"Kalau kamu kangen, cari aku.\"\n";
            cout << "Choice: ";
            cin >> r2;
            cout << '\n';

            if (r2 == 1) {
                slowPrint("Kenji: \"Ingat omonganmu.\"\n", 400);
                currentUser.score += 15;
                currentUser.balance += 60;
                cout << "\n[Ending: Small Promise] [+15 Score, +60 Balance]\n";
            } else {
                slowPrint("Kenji: \"Jangan bikin aku nunggu.\"\n", 400);
                currentUser.score += 12;
                currentUser.balance += 50;
                cout << "\n[Ending: Teasing Rival] [+12 Score, +50 Balance]\n";
            }
        } else {
            slowPrint("Kenji: \"Kalau gitu, latihan yang bener.\"\n\n", 400);
            cout << "1. \"Aku bakal nyusul kamu.\"\n";
            cout << "2. \"Aku cuma nggak mau kalah.\"\n";
            cout << "Choice: ";
            cin >> r2;
            cout << '\n';

            if (r2 == 1) {
                slowPrint("Kenji: \"Kita lihat nanti.\"\n", 400);
                currentUser.score += 14;
                currentUser.balance += 55;
                cout << "\n[Ending: Future Champion] [+14 Score, +55 Balance]\n";
            } else {
                slowPrint("Kenji: \"Jangan berhenti di tengah jalan.\"\n", 400);
                currentUser.score += 13;
                currentUser.balance += 50;
                cout << "\n[Ending: Relentless Rival] [+13 Score, +50 Balance]\n";
            }
        }
    } else if (choice == 2) {
        slowPrint("Leo: \"Hii " + name + ", kamu dateng~\"\n\n", 400);
        cout << "1. \"Kamu nunggu aku?\"\n";
        cout << "2. \"Kamu nempel banget.\"\n";
        cout << "Choice: ";
        cin >> r;
        cout << '\n';

        if (r == 1) {
            slowPrint("Leo: \"Iya, soalnya sepi tanpa kamu.\"\n", 400);
            cout << "1. \"Tetap di samping aku.\"\n";
            cout << "2. \"Jangan terlalu sering, ya.\"\n";
            cout << "Choice: ";
            cin >> r2;
            cout << '\n';

            if (r2 == 1) {
                slowPrint("Leo: \"Hehe, aku nggak kemana-mana.\"\n", 400);
                currentUser.score += 15;
                currentUser.balance += 45;
                cout << "\n[Ending: Stay With Me] [+15 Score, +45 Balance]\n";
            } else {
                slowPrint("Leo: \"Baik, tapi aku tetap lihat kamu.\"\n", 5);
                currentUser.score += 12;
                currentUser.balance += 40;
                cout << "\n[Ending: Soft Distance] [+12 Score, +40 Balance]\n";
            }
        } else {
            slowPrint("Leo: \"Aku bakal coba agak mundur.\"\n", 400);
            cout << "1. \"Segini udah pas.\"\n";
            cout << "2. \"Aku nggak keberatan kok.\"\n";
            cout << "Choice: ";
            cin >> r2;
            cout << '\n';

            if (r2 == 1) {
                slowPrint("Leo: \"Kalau gitu aku tetap di sini.\"\n", 400);
                currentUser.score += 13;
                currentUser.balance += 35;
                cout << "\n[Ending: Adjusted Clinginess] [+13 Score, +35 Balance]\n";
            } else {
                slowPrint("Leo: \"Hehe, itu udah cukup buat aku.\"\n", 400);
                currentUser.score += 14;
                currentUser.balance += 38;
                cout << "\n[Ending: Secretly Happy] [+14 Score, +38 Balance]\n";
            }
        }
    } else if (choice == 3) {
        slowPrint("Kurama: \"Jadi kau berani mendekat, " + name + ".\"\n\n", 400);
        cout << "1. \"Aku nggak takut.\"\n";
        cout << "2. \"Aku percaya sama kamu.\"\n";
        cout << "Choice: ";
        cin >> r;
        cout << '\n';

        if (r == 1) {
            slowPrint("Kurama: \"Keberanianmu menarik.\"\n", 400);
            cout << "1. \"Aku bakal buktiin lagi.\"\n";
            cout << "2. \"Cukup lihat aku.\"\n";
            cout << "Choice: ";
            cin >> r2;
            cout << '\n';

            if (r2 == 1) {
                slowPrint("Kurama: \"Jangan goyah lain kali.\"\n", 400);
                currentUser.score += 18;
                currentUser.balance += 70;
                cout << "\n[Ending: Steadfast Partner] [+18 Score, +70 Balance]\n";
            } else {
                slowPrint("Kurama: \"Baik, aku akan mengawasimu.\"\n", 400);
                currentUser.score += 17;
                currentUser.balance += 65;
                cout << "\n[Ending: Under His Gaze] [+17 Score, +65 Balance]\n";
            }
        } else {
            slowPrint("Kurama: \"Kepercayaanmu... jangan disia-siakan.\"\n", 400);
            cout << "1. \"Aku nggak akan mundur.\"\n";
            cout << "2. \"Selama kamu di sisiku.\"\n";
            cout << "Choice: ";
            cin >> r2;
            cout << '\n';

            if (r2 == 1) {
                slowPrint("Kurama: \"Kalau begitu, berdirilah tegak.\"\n", 400);
                currentUser.score += 22;
                currentUser.balance += 80;
                cout << "\n[Ending: Honest Darkness] [+22 Score, +80 Balance]\n";
            } else {
                slowPrint("Kurama: \"Mulai sekarang, aku yang jaga.\"\n", 400);
                currentUser.score += 25;
                currentUser.balance += 90;
                cout << "\n[Ending: Home of the Beast] [+25 Score, +90 Balance]\n";
            }
        }
    } else {
        cout << "Invalid choice!\n";
    }

    cout << "\n(End of mini-scenario)\n";
}

// menampilkan profile
void showProfile() {
    cout << "\n===== PROFIL =====\n";
    cout << "Nama panggilan : " << currentUser.nickname << '\n';
    cout << "Score          : " << currentUser.score   << '\n';
    cout << "Balance        : " << currentUser.balance << '\n';
}

void mainMenu() {
    int choice = 0;

    while (true) {
        cout << "\n============================\n";
        cout << "        MAIN MENU\n";
        cout << "============================\n";
        cout << "1. Play Pop Quiz\n";
        cout << "2. Play Gamble\n";
        cout << "3. Play Halu\n";
        cout << "4. Lihat Profile\n";
        cout << "5. Logout\n";
        cout << "Pilih menu: ";
        cin  >> choice;

        switch (choice) {
            case 1:
                playPopQuiz();
                break;
            case 2:
                playGamble();
                break;
            case 3:
                playHalu();
                break;
            case 4:
                showProfile();
                break;
            case 5:
                return;
            default:
                cout << "\nPilihan tidak valid.\n";
        }
    }
}

int main() {
    loadAccounts();

    int  choice    = 0;
    bool loggedIn  = false;

    while (true) {
        cout << "\n=================================\n";
        cout << "        WELCOME TO MULTIGAME\n";
        cout << "=================================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Pilih menu: ";
        cin  >> choice;

        switch (choice) {
            case 1:
                registerAccount();
                break;

            case 2:
                loggedIn = loginAccount();
                if (loggedIn) {
                    mainMenu();
                }
                break;

            case 3:
                cout << "\nKeluar program...\n";
                return 0;

            default:
                cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}
