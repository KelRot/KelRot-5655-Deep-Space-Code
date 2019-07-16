# Kaynaklar ve genel linkler

[Robot ve oyun hakkında](#robot-ve-oyun-hakkında) \
[Elektronik sistem](#elektronik-sistem) \
[Robot ve oyun hakkında](#robot-ve-oyun-hakkında)
[Sistemler](#sistemler) 
- [Sürüş Sistemi](#sürüş-sistemi) 
- [Asansör Sistemi](#asansör-sistemi) 
- [Intake Açılıp Kapanma Sistemi](#asansör-sistemi) 
- [Intake Cargo Alma Sistemi](#intake-cargo-alma-sistemi) ak-
Kelrot #5655 takımının [FRC](https://www.firstinspires.org/robotics/frc) 2019 Deep Space yarışması için hazırladığı robotun kodlarıdır.FIRST tarafından önerildiği üzere Visual Studio Code IDE'si ile birlikte WPIlib eklentisi kullanılarak ve C++ dili tercih edilerek yazıldı. Geliştirme ekosistemin kurulumu hakkında detaylı bilgi [burada](https://wpilib.screenstepslive.com/s/currentCS/m/cpp/c/57252) bulunabilir.
 Ek olarak C++ kullanılarak robot kodu hazırlama ile ilgili  detaylı bilgi [FRC C++ Programming](https://wpilib.screenstepslive.com/s/currentCS/m/cpp) sayfasında bulunabilir.

 FRC takımlarının yarışabilmesi için FIRST tarafından temin edilen [elektronik kitini](https://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/599672-frc-control-system-hardware-overview)
 kullanmaları gerekir. 2015 yılından bu yana da robot kontrolcüsü olarak [roboRIO](file:///C:/Users/egeok/Downloads/Documents/374474a.pdf) kullanılmakta ve yine yarışma standartı gereği içine [FRC yazılımı](https://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/1009233-imaging-your-roborio) yüklenmektedir.
 Bu şekilde robot kontrolcüsü [FRC Update Suite](https://wpilib.screenstepslive.com/s/currentCS/m/cpp/l/1027499-installing-the-frc-update-suite-all-languages) içindeki yazılımlar ile kontrol edilebilir, haberleşebilir ve [WPIlib eklentisi](https://github.com/wpilibsuite/vscode-wpilib) ve [GradleRIO](https://github.com/wpilibsuite/GradleRIO) ile kod derlenip yüklenebilir. WPIlib hakkında temel bilgiler de [burada](https://wpilib.screenstepslive.com/s/currentCS/m/cpp/l/241852-what-is-wpilib) bulunabilir.

 Kod yazılırken içerisinde FRC robotu ile ilgili ana kontrolleri sağlayan [WPIlib kütüphanesi](https://first.wpi.edu/FRC/roborio/release/docs) ve görüntü işleme çalışmalarımız için [OpenCV kütüphanesi](https://docs.opencv.org/master/) kullanıldı. Linklerdeki dokümentasyonlardan sınıflar ve methodlar hakkında detaylı bilgi alabilirsiniz.
 
 Diğer faydalı linkler: \
 [FIRST ana sayfası](https://www.firstinspires.org/) \
 [Chief Delphi - FRC ile ilgili çoğu sorunuza cevap bulabileceğiniz forum](https://www.chiefdelphi.com) \
 [The Blue Alliance - Takımlar ve etkinlikler hakkında bilgi edinebileceğiniz internet sitesi](https://www.thebluealliance.com/) \
 [FRC resmi Discord grubu](https://discordapp.com/invite/frc) \
 [FRC subredditi](https://www.reddit.com/r/FRC/)

# Robot ve oyun hakkında
Robot, FRC'de her sene olduğu gibi yaklaşık 2.5 dakikalık bir oyunu oynayacak ve içerisindeki görevleri tamamlayacak şekilde tasarlandı ve yapıldı. Kodlanan sistemlerin mantığını daha iyi kavramak için oyun hakkında bilgi sahibi olmanızı tavsiye ederiz. Eğer Deep Space temalı bir FRC etkinliğinde katılımcı iseniz [Game Manuel'i](https://firstfrc.blob.core.windows.net/frc2019/Manual/2019FRCGameSeasonManual.pdf) detaylı şekilde okumanız beklenir. \
[Oyunun kısa tanıtım videosu](https://www.youtube.com/watch?v=Mew6G_og-PI) \
[Daha detaylı bilgi için kaynak merkezi](https://www.firstinspires.org/resource-library/frc/competition-manual-qa-system)

Kısa şekilde anlatmak gerekirse robotun [Cascade](https://www.instructables.com/id/Introduction-to-Manipulators/)???düzeltme pls  tipinde bir asansör ile taşınan ve cargo ile hatch taşıyıp yerleştiren bir intake sistemine sahip olacak şekilde yapılmasına takımca karar verildi. Oyunun sonundaki göreve hitaben ise bir sistem yapılmadı.

! Robot renderı hoş olur.
# Elektronik sistem
[FRC elektroniğine](https://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/599672-frc-control-system-hardware-overview) ve  [nasıl bağlanacağına](https://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/599673-wiring-the-frc-control-system) linklerden ulaşabilirsiniz. Ayrıca  [takım 3128](http://team3128.org/) tarafından hazırlanan elektronik FRC Control System Layout'a da [buradan](https://www.chiefdelphi.com/t/pic-upgraded-frc-control-system-wiring-diagram/1665280) ulaşabilirsiniz.

FRC standartlarına uygun olarak hazırladığımız robot elektroniğinde tercihe bağlı olan bölümlerden bahsedecek olursak; \
RoboRIO'ya CAN aracılığı ile bağlı: \
Asansör motorlarının kontrolü için 2 adet Victor SPX 

RoboRIO'ya PWM aracılığı ile bağlı: \
Sürüş motorlarının kontrolü için 4 adet Talon SR, \
Intake'in cargo almasına yarayan motorlar için 2 adet Victor SP

roboRIO'ya Digital I/O portlarında bağlanan sensörler:\
Sürüş kontrolü için gearboxlara yerleştirilen 2 adet SRX Magnetic Encoder

PCM'e bağlı: \
Hatch yapıştırmak için pistonu kontrol eden 1 adet Double Solenoid \
Intake'i aşağıda tutmak için 2 pistonu kontrol eden 1 adet Double Solenoid 

Robottaki CAN yolu PDB-RoboRIO-Victor SPX'ler-PCM şeklinde bağlanmıştır. PCM ve PDB ile roboRIO iletişimi kütüphanelerde varsayılan olarak [CAN bus](https://wpilib.screenstepslive.com/s/currentCS/m/java/l/599694-using-the-can-subsystem-with-the-roborio) aracılığı ile sağlandığından kod kullanımında herhangi bir sıkıntı yaşanmamaktadır. Ancak iş CAN bus ile bağlanan Victor SPX ve Talon SRX gibi motor sürücülerine geldiğinde WPIlib kütüphanesindeki [SpeedController](https://first.wpi.edu/FRC/roborio/release/docs/cpp/classfrc_1_1SpeedController.html#details) sınıfının PWM ile sinyal vermeyi desteklediğini görüyoruz. CAN bus ile bağlanan bu motor sürücüleri kontrol etmek için Cross The Road Electronics'in kütüphanelerini robot kodu projesine aktarımını sağlamak ve yine aynı firmaya ait Phoenix yazılımı ile CAN aygıtlarının kurulumunu yapmak gerekti.

Kurulum için faydalı linkler: \
[Phoenix dokümentasyonu ana sayfası](https://phoenix-documentation.readthedocs.io/en/latest/) \
[Motor sürücü testleri ve ince ayarları](https://phoenix-documentation.readthedocs.io/en/latest/ch13_MC.html) \
[Phoenix hakkında temel bilgiler](https://phoenix-documentation.readthedocs.io/en/latest/ch03_PrimerPhoenixSoft.html) \
[Phoenix'in kurulumu](https://phoenix-documentation.readthedocs.io/en/latest/ch05_PrepWorkstation.html) \
[roboRIO'yu hazırlama](https://phoenix-documentation.readthedocs.io/en/latest/ch06_PrepRobot.html) \
[CAN Bus'ı kurma ve Phoenix ile kurulumu tamamlama](https://phoenix-documentation.readthedocs.io/en/latest/ch08_BringUpCAN.html) \
[Kütüphaneleri projeye ekleme](https://phoenix-documentation.readthedocs.io/en/latest/ch05a_CppJava.html) 

Kurulumu yaparken biz bu linklerden yararlandık. Daha detaylı bilgiyi dokümentasyonun içinde bulabilirsiniz.
 
 Ek olarak PWM ve CAN hakkında bilgi almak için [buradan](https://alex-spataru.gitbooks.io/frc-robot-programming/content/Book/Chapters/1.3.html) hala hazırlanmakta olan bir FRC Programlama rehberinin ilgili bölümünü inceleyebilirsiniz.
# Sistemler
joystickten de bahset
- # Sürüş sistemi
Drive alternatifleri için linkler Differential Drive ayrıca wpilib documentation gömülü
Neden Curvature drive
spx ile motor sürme
```cpp
  frc::Talon m_frontRight{2};
  frc::Talon m_rearRight{3};
  frc::Talon m_frontLeft{4};
  frc::Talon m_rearLeft{4};
  
  frc::SpeedControllerGroup driveMotors_right{m_frontRight,m_rearRight}; 
  frc::SpeedControllerGroup driveMotors_left{m_frontLeft,m_rearLeft};
  frc::DifferentialDrive rd{driveMotors_left,driveMotors_right};
```
```cpp
 rd.CurvatureDrive(drive_js.GetRawAxis(1),drive_js.GetRawAxis(4)*0.75,drive_js.GetRawAxis(7)); 
```

- # Asansör Sistemi
PD kontrol,tuning vs
- # Intake Açılıp Kapanmama Sistemi
Burası çokomelli
- # Intake Cargo Alma Sistemi

```cpp
  void intake();
  
  frc::Victor m_leftIntake{0};//PWM
  frc::Victor m_rightIntake{1};
```
```cpp
void Robot::intake()
{
  if(js.GetPOV()==180)
  {
    m_rightIntake.Set(-1.0);
    m_leftIntake.Set(1.0);
  }
  else if(js.GetPOV()==0)
  {
    m_rightIntake.Set(1.0);
    m_leftIntake.Set(-1.0);
  } 
  else
  {
   m_rightIntake.Set(0.0);
   m_leftIntake.Set(0.0);
  } 
}
```

Düz motor çalıştırma
- # Intake Hatch Asma Sistemi

Düz piston çalıştırma
# Ekstra Kontrol Sistemleri
Joystick hazırlama - esadın repoya link ver. \
Otonom çalışması ve fikri.

# Kapanış-Teşekkür
