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

void saveAccounts() {
    ofstream file("accounts.txt");
    for (int i = 0; i < accountCount; i++) {
        file << accounts[i].username << ' '
             << accounts[i].password << ' '
             << accounts[i].nickname << ' '
             << accounts[i].score    << ' '
             << accounts[i].balance  << '\n';
    }
    file.close();
}

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

void updateCurrentUser() {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].username == currentUser.username) {
            accounts[i] = currentUser;
            break;
        }
    }
    saveAccounts();
}

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

        // -------------------------
        // Pertanyaan 1
        // -------------------------
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
            tempScore         += 10;
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
            tempScore         += 10;
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
            tempScore         += 10;
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
            tempScore         += 10;
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
            tempScore         += 10;
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

void slowPrint(const string& text, int delayMs = 15) {
    for (size_t i = 0; i < text.size(); ++i) {
        cout << text[i];
        cout.flush();

        clock_t start = clock();
        while (clock() - start <
               delayMs * CLOCKS_PER_SEC / 1000) {
        
        }
    }
}

void playHalu() {
    int    choice;
    string name = currentUser.nickname;

    cout << "\n============= PLAY HALU =============\n";
    slowPrint("Choose your halu-character, " + name + "...\n\n", 15);

    cout << "1. Kenji  - Rival to Lovers\n";
    cout << "2. Leo    - Soft & Clingy (BL)\n";
    cout << "3. Kurama - The Nine-Tails\n";
    cout << "Your choice: ";
    cin  >> choice;
    cout << '\n';

    int r;
    int r2;

    if (choice == 1) {
        slowPrint("Kenji: \"Tch... why are you here again, " + name + "?\"\n\n", 15);
        cout << "1. \"Relax. I just missed you.\"\n";
        cout << "2. \"I'm here to beat you.\"\n";
        cout << "Choice: ";
        cin  >> r;
        cout << '\n';

        if (r == 1) {
            slowPrint("Kenji: \"H-hah?! Who said I was waiting for you?\"\n", 15);
            slowPrint("       (His cheeks are way too red.)\n", 15);
            slowPrint("Kenji: \"...Next time you leave, tell me. I don't like it when you disappear like that.\"\n\n", 15);

            cout << "Kenji: \"Hey, " << name << "...\"\n";
            cout << "Kenji: \"If one day you really stop coming... where am I supposed to look for you?\"\n";
            cout << "1. \"Look for me on the school rooftop. I'll be waiting.\"\n";
            cout << "2. \"Just call my name. I'll come back on my own.\"\n";
            cout << "Choice: ";
            cin  >> r2;
            cout << '\n';

            if (r2 == 1) {
                slowPrint("Kenji: \"Hmph... dramatic much.\"\n", 15);
                slowPrint("Kenji: \"If you don't show up there, I'll drag you down from every classroom one by one.\"\n", 15);
                currentUser.score   += 18;
                currentUser.balance += 70;
                cout << "\n[Ending: Rooftop Promise] [+18 Score, +70 Balance]\n";
            } else {
                slowPrint("Kenji: \"...Seriously. You talk like an anime protagonist.\"\n", 15);
                slowPrint("Kenji: \"Then don't make me wait too long, got it?\"\n", 15);
                currentUser.score   += 14;
                currentUser.balance += 60;
                cout << "\n[Ending: Call My Name] [+14 Score, +60 Balance]\n";
            }
        } else {
            slowPrint("Kenji: \"Beat me? Dream big, huh.\"\n", 15);
            slowPrint("Kenji: \"...But to be honest, you've gotten way stronger since last time.\" *glances briefly*\n\n", 15);

            cout << "Kenji: \"How many hours do you train a day to get this far?\"\n";
            cout << "1. \"Enough that I lose track of time.\"\n";
            cout << "2. \"Not much. I just don't want to lose to you.\"\n";
            cout << "Choice: ";
            cin  >> r2;
            cout << '\n';

            if (r2 == 1) {
                slowPrint("Kenji: \"Idiot. Don't get sick just because you want to catch up to me.\"\n", 15);
                slowPrint("Kenji: \"...If you collapse, who's gonna be my rival?\"\n", 15);
                currentUser.score   += 16;
                currentUser.balance += 55;
                cout << "\n[Ending: Overtraining Rival] [+16 Score, +55 Balance]\n";
            } else {
                slowPrint("Kenji: \"Heh. So you train because of me, huh?\"\n", 15);
                slowPrint("Kenji: \"Then don't even think about quitting halfway. I won't accept a weak rival.\"\n", 15);
                currentUser.score   += 15;
                currentUser.balance += 50;
                cout << "\n[Ending: For You, Rival] [+15 Score, +50 Balance]\n";
            }
        }
    } else if (choice == 2) {
        slowPrint("Leo: \"Hiiii " + name + "! You really came~ I've been waiting, y'know.\"\n\n", 15);
        cout << "1. \"You really waited for me?\"\n";
        cout << "2. \"You're so clingy, Leo...\"\n";
        cout << "Choice: ";
        cin  >> r;
        cout << '\n';

        if (r == 1) {
            slowPrint("Leo: \"Of course. When you're not here, everything feels empty.\"\n", 15);
            slowPrint("Leo: \"Is it okay if I stay by your side like this forever?\"\n\n", 15);

            cout << "Leo: \"If one day I suddenly disappear from here...\"\n";
            cout << "Leo: \"Where would you look for me first?\"\n";
            cout << "1. \"Every place we've been together.\"\n";
            cout << "2. \"The place we first met.\"\n";
            cout << "Choice: ";
            cin  >> r2;
            cout << '\n';

            if (r2 == 1) {
                slowPrint("Leo: \"Ehehe~ that sounds like a high-budget romance route. I love it.\"\n", 15);
                slowPrint("Leo: \"If that's the case, I'll leave clues so you can find me faster.\"\n", 15);
                currentUser.score   += 18;
                currentUser.balance += 50;
                cout << "\n[Ending: Chasing Footprints] [+18 Score, +50 Balance]\n";
            } else {
                slowPrint("Leo: \"Eh? You still remember that place?\"\n", 15);
                slowPrint("Leo: \"If you really go there just to find me... I won't leave you again, promise.\"\n", 15);
                currentUser.score   += 16;
                currentUser.balance += 45;
                cout << "\n[Ending: First Meeting, Again] [+16 Score, +45 Balance]\n";
            }
        } else {
            slowPrint("Leo: \"Ehhh? But I like being close to you...\"\n", 15);
            slowPrint("Leo: \"Okay... I'll step back a little. Just don't push me too far, okay?\"\n\n", 15);

            cout << "Leo: \"If I keep this distance... would you still look my way?\"\n";
            cout << "1. \"Yeah. My eyes are used to searching for you.\"\n";
            cout << "2. \"Depends. Are you still smiling at me?\"\n";
            cout << "Choice: ";
            cin  >> r2;
            cout << '\n';

            if (r2 == 1) {
                slowPrint("Leo: \"Hehe... don't say stuff like that or I won't be able to step back at all.\"\n", 15);
                slowPrint("Leo: \"If your eyes always look for me, I promise I'll always stay in your sight.\"\n", 15);
                currentUser.score   += 14;
                currentUser.balance += 35;
                cout << "\n[Ending: Always in Sight] [+14 Score, +35 Balance]\n";
            } else {
                slowPrint("Leo: \"Ooh, so the key is my smile, huh?\"\n", 15);
                slowPrint("Leo: \"Then from now on, I'll smile every time you look at me. Don't get startled.\"\n", 15);
                currentUser.score   += 13;
                currentUser.balance += 30;
                cout << "\n[Ending: Smile Trigger] [+13 Score, +30 Balance]\n";
            }
        }
    } else if (choice == 3) {
        slowPrint("Kurama: \"So, you dare approach me... " + name + ".\"\n", 15);
        slowPrint("        (His heavy aura makes the air vibrate.)\n\n", 15);

        cout << "1. \"I'm not afraid of you.\"\n";
        cout << "2. \"I came because I trust you.\"\n";
        cout << "Choice: ";
        cin  >> r;
        cout << '\n';

        if (r == 1) {
            slowPrint("Kurama: \"Your courage borders on stupidity... but it's interesting.\"\n", 15);
            slowPrint("Kurama: \"Prove it again next time, and maybe I'll acknowledge you as a partner.\"\n\n", 15);

            cout << "Kurama: \"If the world turns against you because you stand by my side...\"\n";
            cout << "Kurama: \"Will you still call my name without fear?\"\n";
            cout << "1. \"As long as you're on my side, I won't step back.\"\n";
            cout << "2. \"I'll shout your name even louder.\"\n";
            cout << "Choice: ";
            cin  >> r2;
            cout << '\n';

            if (r2 == 1) {
                slowPrint("Kurama: \"Hmph. A fitting answer for someone who wishes to be my partner.\"\n", 15);
                slowPrint("Kurama: \"Then never bow your head before me. Only enemies have the right to fear.\"\n", 15);
                currentUser.score   += 20;
                currentUser.balance += 70;
                cout << "\n[Ending: Unshaken Partner] [+20 Score, +70 Balance]\n";
            } else {
                slowPrint("Kurama: \"You're insane... but courage like that isn't easily broken.\"\n", 15);
                slowPrint("Kurama: \"If you call me, I will answer. Don't forget your own words.\"\n", 15);
                currentUser.score   += 18;
                currentUser.balance += 65;
                cout << "\n[Ending: Roaring Name] [+18 Score, +65 Balance]\n";
            }
        } else {
            slowPrint("Kurama: \"...Trust? In a beast like me?\"\n", 15);
            slowPrint("Kurama: \"Don't betray that trust, or I will drag you from the darkness myself.\"\n\n", 15);

            cout << "Kurama: \"What makes you confident enough to entrust your back to a ‘monster'?\"\n";
            cout << "1. \"Because you never lie about who you are.\"\n";
            cout << "2. \"Because even monsters can be a safe home.\"\n";
            cout << "Choice: ";
            cin  >> r2;
            cout << '\n';

            if (r2 == 1) {
                slowPrint("Kurama: \"Honesty about the darkness, hm? Humans usually run from that.\"\n", 15);
                slowPrint("Kurama: \"As long as you look at me like that, I won't betray your trust.\"\n", 15);
                currentUser.score   += 22;
                currentUser.balance += 80;
                cout << "\n[Ending: Honest Darkness] [+22 Score, +80 Balance]\n";
            } else {
                slowPrint("Kurama: \"Calling the place beside me a ‘home'... you're a strange creature.\"\n", 15);
                slowPrint("Kurama: \"Fine. From now on, anyone who disturbs that ‘home' will face me first.\"\n", 15);
                currentUser.score   += 25;
                currentUser.balance += 90;
                cout << "\n[Ending: Home of the Beast] [+25 Score, +90 Balance]\n";
            }
        }
    } else {
        cout << "Invalid choice!\n";
    }


    cout << "\n(End of mini-scenario)\n";
}

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
