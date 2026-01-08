#include <iostream>
#include <chrono>
#include <thread>
#include <string>
using namespace std;

void ketik(string text, int delay_ms = 10) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay_ms));
    }
    cout << endl;
}

class openingDialog{
    public:
    void beforeIndentity(){
        ketik("Kamu tiba-tiba terbangun di suatu padang rumput yang luas, di bawah pohon yang rindang.");
        ketik("Kamu kehilangan semua memorimu, dan tidak mengingat apa-apa.");
        ketik("Tiba-tiba ada suara dari dalam kepalamu bertanya kepadamu.");
    }
};

class identity{
    private:
        string name;
        int age;
        bool isMale;
    public:
        identity() {
            name = "";
            age = 0;
            isMale = true; 
        }
        identity(string nm, int ag, bool gender = true){
            name = nm;
            age = ag;
            isMale = gender;
        }

        void setName(string nm){
            name = nm;
        }

        void setAge(int ag){
            age = ag;
        }

        void setGender(bool gender){
            isMale = gender;
        }

        string getName(){
            return name;
        }

        int getAge(){
            return age;
        }

        bool getGender(){
            return isMale;
        }
    
        void askName(){
            ketik("Kamu ingin dipanggil siapa?");
            cout << "Aku ingin dipanggil ";
            getline(cin, name);
            ketik("Well, hello " + name +"!");
        }

        void askAge(){
            ketik("Berapa umurmu sekarang? (0-100)");
            cout << "Aku sekarang berumur ";
            cin >> age;
           ketik("Oh iya, sekarang aku berumur " + to_string(age) + " tahun.");
        }

        void askGender(){
            char inpGender;
            ketik("Apakah kamu laki-laki atau perempuan? (L/P)");
            cout << "Aku adalah ";
            cin >> inpGender;

            while (inpGender != 'L' && inpGender != 'P' && inpGender != 'l' && inpGender != 'p'){
                cout << "Input tidakk valid. Pilih salah satu dari dua jenis kelamin\n";
                cout << "Aku adalah ";
                cin >> inpGender;
            }
            isMale = (inpGender == 'L' || inpGender == 'l');
            ketik("Dan aku adalah seorang " + string(isMale ? "laki-laki." : "perempuan."));
        }
};

class afterIdentity{
    private:
        identity& id;
    public:
        afterIdentity(identity& idnObj) : id(idnObj){}

        void aftIdn1(){
            ketik("Kemudian kamu kembali bertanya-tanya pada dirimu sendiri...");
            ketik("\"Kenapa aku bisa ada disini?\"");
            ketik("\"Dimanakah aku?\"");
            ketik("Lalu kamu melihat ke sekeliling dan hanya terdapat padang rumput serta beberapa pohon yang berjarak antar satu sama lain.");
            ketik("Kamu merasa bahwa pemandangan ini biasanya hanya dapat terlihat di film-film fantasi atau novel dan komik.");
            ketik("Namun kamu merasakan sendiri bahwa apa yang kamu lihat dan rasakan saat ini sungguh nyata.");
            ketik("Mulai dari sepoi angin, suara rumput dan daun saling bergesekan, serta aroma tanah dan rumput yang khas di padang.");
            ketik("Kamu mulai menatap ke atas.");
            ketik("Langit biru di atas sana tetap membentang tenang, tapi hatimu terasa bergemuruh.");
            ketik("Seolah dunia ini menyimpan sesuatu—sesuatu yang besar...");
            ketik("...dan kau adalah bagian penting dari cerita itu.");
            ketik("...");
            ketik("Tiba-tiba angin berhembus kencang.");
            ketik("Daun-daun beterbangan.");
            ketik("Lalu tiba-tiba ada suara samar-samar yang berkata...");
            bangkit();
        }

        void bangkit(){
            ketik("\"Bangkitlah " + id.getName() + ", petualanganmu baru saja akan dimulai.\"");
            ketik("\"Umurmu baru menginjak usia " + to_string(id.getAge()) + " tahun, perjalananmu masih panjang!\"");
        }

        void aftIdn2(){
            ketik("Kamu berdiri dari tempatmu duduk di bawah pohon dan meregangkan pinggangmu.");
            ketik(id.getName() + ": \"Sudah saatnya aku berkeliling ke sekitar.\"");
            ketik("Kamu melihat ke sekitar dan berjalan sejauh 500 meter ke arah matahari terbit.");
            ketik("Namun tak lama, kamu berhenti dan melihat sesuatu...");
            ketik(id.getName() + ": \"Aku tidak percaya akan hal ini, aku melihat rumah-rumah, mungkin itu sebuah desa!\"");
        }

        void toVillage(){
            ketik("Kamu memutuskan untuk berjalan menuju ke desa tersebut...");
        }

        void wandering(){
            ketik("Kamu memilih untuk menjelajah kembali padang rumput ini.");
        }

        void branch1(){
            string c1;
            ketik("Pergi ke desa tersebut? (Ya/Tidak)");
            cout << "Jawabanmu: ";
            cin >> c1; 

            while (c1 != "Ya" && c1 != "ya" && c1 != "Tidak" && c1 != "tidak"){
                cout << "Pilihanmu tidak valid, silakan pilih ya/tidak";
                cin >> c1;  
            }

            if (c1 == "Ya" || c1 == "ya"){
                toVillage();
            } else{
                wandering();
            }

        }
};

class welcomeVillage{
    private:
        identity& id;
    public:
        void villd1(){
            ketik("Angin sepoi yang awalnya tercium bau padang rumput, perlahan berubah menjadi aroma kayu bakar dan bunga liar.");
            ketik("Dari kejauhan ketika kamu melangkah, terlihat kepulan asap tipis membumbung dari cerobong rumah-rumah kecil.");
            ketik("Desa yang nampak tidak terlalu besar, namun nyaman dan harmonis sudah di depan matamu.");
            ketik("Tanpa berpikir panjang, kakimu mulai melangkah ke arah sana.");
            ketik("Semakin dekat kamu melangkah, suara hewan peliharaan warga dan obrolan sayup mulai terdengar.");
            ketik("Saat itu masih tengah hari, tidak terlalu banyak warga yang beraktivitas di dalam desa.");
            ketik("\"Mungkin karena sudah jam makan siang, desa ini menjadi terlihat agak sepi ya,\" katamu dalam diam.");
            ketik("Kamu tersenyum dan menyapa warga desa yang sedang menyapu maupun beraktivitas di depan rumah-rumah.");
            ketik("Mereka menyapa balik dan tersenyum kepadamu.");
            ketik(id.getName() + "\"Wow, nampaknya warga desa sini sudah biasa melihat petualang asing berlalu-lalang di desanya.\"");
        }
};

class wentWandering{
    private: 
        identity& id;
    public:
        void wanderEnd(){
               ketik("Di tengah perjalanan, kamu melihat semak-semak di depan sebuah hutan.");
               ketik("Karena penasaran, kamu berjalan maju dan memasuki hutan tersebut tanpa peralatan.");
               ketik("Ternyata hutan tersebut sangatlah luas dan rimbun.");
               ketik("Bau tanah khas hutan, suara ranting patah dan warna hijau dedaunan sekarang yang menemanimu dalam perjalanan.");
               ketik("Setelah 30 menit berjalan, kamu merasa kelaparan.");
               ketik("Kamu memutuskan untuk berhenti sejenak dan mencari buah-buahan di suatu semak.");
               ketik("Namun aneh, semak tersebut tampak bergerak sedikit demi sedikit.");
               ketik("Kamu berusaha mendekati semak tersebut...");
               ketik("...");
               ketik("TERNYATA SEEKOR HARIMAU DATANG MENERKAMMU DARI DALAM SEMAK TERSEBUT!");
               ketik("Tubuhmu habis dilahap sang harimau...");
               ketik("Perjalanan pun berakhir...");
        }

        void end01(){
            ketik("ENDING 1");
            ketik("THE FOOL");
            
        }
};


int main(){
    identity id;
    openingDialog od;

    od.beforeIndentity();
    id.askName();
    id.askAge();
    id.askGender();

    afterIdentity afti(id);
    afti.aftIdn1();
    afti.aftIdn2();
    afti.branch1();



    return 0;
}