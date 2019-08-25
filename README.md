# Kaynaklar ve genel linkler

[Robot ve oyun hakkında](#robot-ve-oyun-hakkında) \
[Elektronik sistem](#elektronik-sistem) \
[Robot ve oyun hakkında](#robot-ve-oyun-hakkında) \
[Sistemler](#sistemler) 
- [Sürüş Sistemi](#sürüş-sistemi) 
- [Asansör Sistemi](#asansör-sistemi) 
- [Intake Açılıp Kapanmama Sistemi](#intake-açılıp-kapanmama-sistemi) 
- [Intake Cargo Alma ve Atma Sistemi](#intake-cargo-alma-ve-atma-sistemi)
- [Intake Hatch Asma Sistemi](#intake-hatch-asma-sistemi) 

[Ekstra Kontrol Sistemleri](#ekstra-kontrol-sistemleri) \
[Son notlar](#son-notlar) 

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
 [r/FRC](https://www.reddit.com/r/FRC/)

# Robot ve oyun hakkında
Robot, FRC'de her sene olduğu gibi yaklaşık 2.5 dakikalık bir oyunu oynayacak ve içerisindeki görevleri tamamlayacak şekilde tasarlandı ve yapıldı. Kodlanan sistemlerin mantığını daha iyi kavramak için oyun hakkında bilgi sahibi olmanızı tavsiye ederiz. Eğer Deep Space temalı bir FRC etkinliğinde katılımcı iseniz [Game Manuel'i](https://firstfrc.blob.core.windows.net/frc2019/Manual/2019FRCGameSeasonManual.pdf) detaylı şekilde okumanız beklenir. \
[Oyunun kısa tanıtım videosu](https://www.youtube.com/watch?v=Mew6G_og-PI) \
[Daha detaylı bilgi için kaynak merkezi](https://www.firstinspires.org/resource-library/frc/competition-manual-qa-system)

Kısa şekilde anlatmak gerekirse robotun [Cascade](https://www.instructables.com/id/Introduction-to-Manipulators/)???düzeltme pls  tipinde bir asansör ile taşınan ve cargo ile hatch taşıyıp yerleştiren bir intake sistemine sahip olacak şekilde yapılmasına takımca karar verildi. Oyunun sonundaki tırmanma görevine hitaben ise bir sistem yapılmadı.

! Robot renderı hoş olur.
# Elektronik sistem
[FRC elektroniğine](https://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/599672-frc-control-system-hardware-overview) ve  [nasıl bağlanacağına](https://wpilib.screenstepslive.com/s/currentCS/m/getting_started/l/599673-wiring-the-frc-control-system) linklerden ulaşabilirsiniz. Ayrıca  [takım 3128](http://team3128.org/) tarafından hazırlanan elektronik FRC Control System Layout'a da [buradan](https://www.chiefdelphi.com/t/pic-upgraded-frc-control-system-wiring-diagram/1665280) ulaşabilirsiniz.

FRC standartlarına uygun olarak hazırladığımız robot elektroniğinde tercihe bağlı olan bölümlerden bahsedecek olursak; 

RoboRIO'ya CAN aracılığı ile bağlı: \
Asansör motorlarının kontrolü için 2 adet [Victor SPX](http://www.ctr-electronics.com/victor-spx.html)  

RoboRIO'ya PWM aracılığı ile bağlı: \
Sürüş motorlarının kontrolü için 4 adet Talon SR [Talon SR](http://www.andymark.com/Talon-p/am-talon-discontinued.html), \
Intake'in cargo almasına yarayan motorlar için 2 adet [Victor SP](https://www.ctr-electronics.com/downloads/pdf/Victor-SP-Quick-Start-Guide.pdf)

roboRIO'ya Digital I/O portlarında bağlanan sensörler:\
Sürüş kontrolü için gearboxlara yerleştirilen 2 adet [SRX Magnetic Encoder](http://www.ctr-electronics.com/srx-magnetic-encoder.html)

PCM'e bağlı: \
Hatch yapıştırmak için pistonu kontrol eden 1 adet [Double Solenoid](https://www.andymark.com/products/double-solenoid-valve-mead-1-8-npt) \
Intake'i aşağıda tutmak için 2 pistonu kontrol eden 1 adet [Double Solenoid](https://www.andymark.com/products/double-solenoid-valve-mead-1-8-npt) 

Robottaki CAN yolu PDB-RoboRIO-Victor SPX'ler-PCM şeklinde bağlanmıştır. PCM ve PDB ile roboRIO iletişimi kütüphanelerde varsayılan olarak [CAN bus](https://wpilib.screenstepslive.com/s/currentCS/m/java/l/599694-using-the-can-subsystem-with-the-roborio) aracılığı ile sağlandığından kod kullanımında herhangi bir sıkıntı yaşanmamaktadır. Ancak iş CAN bus ile bağlanan Victor SPX ve Talon SRX gibi motor sürücülerine geldiğinde WPIlib kütüphanesindeki [SpeedController](https://first.wpi.edu/FRC/roborio/release/docs/cpp/classfrc_1_1SpeedController.html#details) sınıfının PWM ile sinyal vermeyi desteklediğini görüyoruz. CAN bus ile bağlanan bu motor sürücüleri kontrol etmek için [Cross The Road Electronics](http://www.ctr-electronics.com/)'in kütüphanelerini robot kodu projesine aktarımını sağlamak ve yine aynı firmaya ait Phoenix yazılımı ile CAN aygıtlarının kurulumunu yapmak gerekti.

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
WPIlib'de robot projesi oluşturulduğu zaman verilen robot sınıfı oyunun farklı bölümlerine hitap eden bazı temel methodlar içerir. Bunlardan bazıları :

  `RobotInit()` RoboRIO kodu çalıştırır çalıştırmaz başlayan methoddur ve bir kere çalışır. \
  `RobotPeriodic() ` RoboRIO kodu çalıştırdığı sürece döngü halinde çalışır\
  `AutonomousInit() ` Robotun oyunun başlangıcındaki otonom bölümü için hazırlanması için bir kere çalışır. \
  `AutonomousPeriodic() ` Robot otonom bölümündeyken döngü halinde çalışır\
  `TeleopInit() ` Robotlar kumandayla kontrol periyoduna geçmeden önce bir kere çalışır. \
  `TeleopPeriodic() ` Robot otonom kumandayla kontrol periyodundayken döngü halinde çalışır\
  `TestPeriodic()` Oyun sırasında çalışmaz, kod denemek içindir ve Driver Station'dan aktif edilirse döngü halinde çalışır\
  `DisableInıt()` Oyun bitiminde veya Driver Station tarafından robot disabled hale getirildiğinde bir kere çalışır. \
  `DisablePeriodic()` Robot disabled haldeyken döngü halinde çalışır.
  > Not: Her döngü Driver Station haberleşmesi ve kullanılan robot sınıfına bağlı olarak ~20 ms'de bir çalışır.

  Bu methodlarla oluşturulan [örnek programı](https://wpilib.screenstepslive.com/s/currentCS/m/cpp/l/145319-creating-your-benchtop-test-program) linkte bulabilirsiniz.

  Çoğu FRC oyununda otonom periyodu sırasında sürücülerin kumandayla müdahale etmesine izin verilmemektedir. Ancak 2019 yılı Deep Space oyununda bu kural kaldırılarak kamera sistemi kullanarak robot kontrolüne izin verildi. Bu sebepten dolayı kodu yazarken hem otonom hem de kumandayla kontrol periyodu için ortak bir method olarak `Robot::Periodic`'i kullandık

  ```cpp
//Robot.cpp  
void Robot::AutonomousPeriodic() {
  Periodic();
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  Periodic();
}
  ``` 
- ## Sürüş sistemi

FRC oyunlarında hiç değişmeyen bir şey var ise bu da robotların saha düzleminde hareket etmeleridir. Bu hareketi sağlamak için [Kit of Parts](https://www.firstinspires.org/robotics/frc/kit-of-parts) kapsamında olan [AM14U4](https://www.andymark.com/products/am14u4-kit-of-parts-chassis?via=Z2lkOi8vYW5keW1hcmsvV29ya2FyZWE6OkNhdGFsb2c6OkNhdGVnb3J5LzVhZjhkN2Y1YmM2ZjZkNWUzNmYyMzRkOA) kodlu drive base'i kullandık. 
 Yani Differential Drive sınıfına giren bir sürüş sistemine sahip olduk. [Sürüş sistemleri](https://wpilib.screenstepslive.com/s/currentCS/m/java/l/914814-wpilib-drive-classes-drivetrain-types) ile ilgili detaylı bilgiyi linkte bulabilirsiniz. 

```cpp
  //Robot.h
  frc::Joystick drive_js{0};

  frc::Talon frontRight{2}; //PWM
  frc::Talon rearRight{3};
  frc::Talon frontLeft{4};
  frc::Talon rearLeft{4};
  
  frc::SpeedControllerGroup driveMotors_right{m_frontRight,m_rearRight}; 
  frc::SpeedControllerGroup driveMotors_left{m_frontLeft,m_rearLeft};
  frc::DifferentialDrive rd{driveMotors_left,driveMotors_right};
```
Kodu yazarken de buna uygun olarak `DifferentialDrive`  sınıfını kullandık. Sınıfın kullanımı için [burayı](https://wpilib.screenstepslive.com/s/currentCS/m/java/l/914148-driving-a-robot-using-differential-drive) ziyaret edebilirsiniz. Daha da detaylı açıklama için [WPIlib dokümentasyonunun ilgili sayfasına](https://first.wpi.edu/FRC/roborio/release/docs/cpp/classfrc_1_1DifferentialDrive.html) bakılabilir.

Motor sürücü olarak Talon SR tercih ettik. Robot ani frenlerde devrilebileceği için [coast](https://firstwiki.github.io/wiki/talon-sr#coastbrake) modunu ayarladık. 
```cpp
 //Robot.cpp > Robot::Periodic()
 rd.CurvatureDrive(drive_js.GetRawAxis(1), drive_js.GetRawAxis(4)*0.75 ,drive_js.GetRawAxis(7)); 
```
Yukarıdaki linklerde anlatıldığı üzere sürüş methodunun alternatifleri arasından [CurvatureDrive](https://first.wpi.edu/FRC/roborio/release/docs/cpp/classfrc_1_1DifferentialDrive.html#a7f6af2233e75b79f70faaac79c929e87)'ı seçtik.  Kullanımı linkte olan bu methodu seçmemizde yüksek hızlardaki kontrol kolaylığı ve quick turn butonu ile keskin dönüşler yapabilmesi öne çıktı.

Ayrıca methoda girilen parametreler görüldüğü üzere kumandadan `Joystick` sınıfı kullanılarak veriliyor. Joystick kullanımı ile ilgili aşağıdaki linklerden faydalanılabilir.
[Driver Station hakkında](https://wpilib.screenstepslive.com/s/currentCS/m/24192?data-resolve-url=true&data-manual-id=24192) \
[Drive Station girdileri](https://wpilib.screenstepslive.com/s/currentCS/m/cpp/l/241880-driver-station-input-overview) \
[Joystickler](https://wpilib.screenstepslive.com/s/currentCS/m/cpp/l/241881-joysticks)

Eğer Victor SPX veya Talon SRX ile yukarıdaki sınıfları kullanmak isterseniz hatayla karşılaşabilirsiniz. Bunun sebebi sonradan eklenen bu motor sürücü sınıflarının WPIlib'de var olan `SpeedController` sınıfından miras almamasıdır. Bu durumu çözmek için PWM'li motor sürücüler yukarıdaki gibi tanımlanıp methoda verilip, sonrasında bu motorun sürücülerin PWM sinyali drive motorlarına verilebilir. Örnek:

```cpp
  //class Robot:
  frc::Spark drive_r; 
  frc::Spark drive_l; 

  VictorSPX frontRight{1};//CAN
  VictorSPX rearRight{2};
  VictorSPX frontLeft{3};
  VictorSPX rearLeft{4};

  frc::DifferentialDrive rd{drive_r,drive_l};
```

```cpp
  //Robot::TeleopPeriodic() veya Robot::AutonomousPeriodic() :
  rd.CurvatureDrive(drive_js.GetRawAxis(1),drive_js.GetRawAxis(4)*0.75,drive_js.GetRawButton(7));
  
  frontRight.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,drive_r.Get());
  rearRight.Follow(m_frontRight);
  frontLeft.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,drive_l.Get());
  rearLeft.Follow(m_frontLeft);

```
- ## Asansör Sistemi


```cpp
//Robot.h
VictorSPX frontLift{0};//CAN 
VictorSPX rearLift{1};

frc::Encoder lift_ec{0,1}; // DI/O

PDController pdc;
int ref;
double baseSpeed;
float kp,kd;

float getLiftHeight();
void setLiftforHatchAndCargo();
void manualLiftControl();
```
```cpp
//Robot.cpp
void Robot::manualLiftControl()
{
  if(js.GetRawButton(3))//*up
   ref +=1.25;
  else if(js.GetRawButton(4))//*down
   ref -=0.25;
}

void Robot::setLiftforHatchAndCargo()
{
  if(drive_js.GetRawButtonPressed(5)){//*ground level
    ref = 0;
  }
  else if(js.GetRawButtonPressed(5)){//*Cargo level 3
    ref=220;
  }
  else if(js.GetRawButtonPressed(6)){//*Cargo level 2
    ref=150;
  }
  else if(js.GetRawButtonPressed(7)){//*Cargo level 1
    ref=80;
  }
  else if(js.GetRawButtonPressed(8)){//*Hatch level 3
    ref=188;
  }
  else if(js.GetRawButtonPressed(9)){//*Hatch level 2
    ref=118;
  }
  else if(js.GetRawButtonPressed(10)){//*Hatch level 1
    ref=32;
  }
}

float Robot::getLiftHeight(){
  float ecRotation = (float)lift_ec.Get()/600; 
  float ilk_katman= ecRotation* 2.0 * 3.14159265 * 1.25;
  return ilk_katman * 3.0 * 1.15;
  /* 3.0=cascade sistemi dolayısıyla son katmanın yüksekliği ilk katmanın 
   üç katı olmalı.
   1.15=ipin düz sarılmamasından dolayı oluşan kaymayı düzeltmek için.
  */
}
```
```cpp
  //Robot.cpp
  void Robot::AutonomousInit() {
  baseSpeed = 1;
  kp=0.008;
  kd=0.075;
  pdc.setkP(kp);
  pdc.setkD(kd);
  ref = 0;

  frontLift.Set(ControlMode::PercentOutput,0);
  rearLift.Set(ControlMode::PercentOutput,0);
  lift_ec.Reset();
  
  //runPControl = false;
}
```
```cpp
  //Robot.cpp > Robot::Periodic
  manualLiftControl();
  setLiftforHatchAndCargo();

  float error = ref-getLiftHeight();
  pdc.setError(error);
  float output = pdc.getOutput();
  baseSpeed += output;
  if(baseSpeed >= 1){
    baseSpeed = 1;
  }
  if(baseSpeed<-1){
    baseSpeed = -1;
  } 
  double speed = baseSpeed;
  frontLift.Set(ControlMode::PercentOutput,speed);
  rearLift.Set(ControlMode::PercentOutput,speed);

  std::cout<<"lift height="<<getLiftHeight()<<std::endl;
  std::cout<<"error="<<error<<std::endl;
```
PD kontrol,tuning vs PD kontrol için ayrı repo?

- ## Intake Açılıp Kapanmama Sistemi
Oyun manuelinde belirtildiği üzere robotlar maça başlamadan önce herhangi bir parçası frame perimeter dışında kalamaz. Ancak intake sisteminin ise çalışma mantığı gereği dışarıda olması gerekiyordu. Buna çözüm olarak iki adet piston maç başlamadan önce intake'i içeride tutuyor ve maç başladıktan sonra sürücü kontrolü ile açılıyor. 

```cpp
//Robot.h
void extension();
frc::DoubleSolenoid intakeLowering{2,3}; //PCM channels
```
İki pistonu kontrol etmek için PCM'e bağlı bir adet [Double Solenoid](https://www.andymark.com/products/double-solenoid-valve-mead-1-8-npt) yeterli oldu. Robot sınıfının içinde operasyonu gerçekleştirmek için bir de `extension()` methodunu ekledik.
```cpp
//Robot.cpp
void Robot::extension(){
  if(js.GetRawButton(1)){
    intakeLowering.Set(frc::DoubleSolenoid::Value::kReverse);
  }
  else if(js.GetRawButton(2)){
    intakeLowering.Set(frc::DoubleSolenoid::Value::kForward);
  }
  else{
    intakeLowering.Set(frc::DoubleSolenoid::kOff);
  }
}
```
Method Joystick inputlarını denetleyip `DoubleSolenoid` sınıfının methodları ile pistonları kontrol ediyor. Pnömatik sistemleri ve kod kullanımları ile ilgili aşağıdaki linklerden bilgi alabilirsiniz.

[Pnömatik manueli-pdf](https://firstfrc.blob.core.windows.net/frc2017/pneumatics-manual.pdf) \
[Kompresör sınıfı ile ilgili bilgi](https://wpilib.screenstepslive.com/s/currentCS/m/cpp/l/241865-operating-a-compressor-for-pneumatics) \
[Solenoid sınıfları ile ilgili bilgi](https://wpilib.screenstepslive.com/s/currentCS/m/cpp/l/241866-operating-pneumatic-cylinders-solenoids) \
[DoubleSolenoid için dokümentaston](https://first.wpi.edu/FRC/roborio/release/docs/cpp/classfrc_1_1DoubleSolenoid.html)
- ## Intake Cargo Alma ve Atma Sistemi
[robot fotoğrafı hoş olur]
Kargo alma sistemi için 2 adet [RS775Pro](http://www.wcproducts.net/217-4347) ve onların çevirdiği sağda ve solda üçer tane toplam 6 adet [compilant wheel](https://www.andymark.com/products/4-in-compliant-wheel-8mm-bore-35a-durometer?via=Z2lkOi8vYW5keW1hcmsvV29ya2FyZWE6Ok5hdmlnYXRpb246OlNlYXJjaFJlc3VsdHMvJTdCJTIyYnV0dG9uJTIyJTNBJTIyc2VhcmNoJTIyJTJDJTIycSUyMiUzQSUyMmNvbXBsaWFudCt3aGVlbCUyMiUyQyUyMnV0ZjglMjIlM0ElMjIlRTIlOUMlOTMlMjIlN0Q) kullandık. 
```cpp
  //Robot.h
  void intake();
  
  frc::VictorSP leftIntake{0};//PWM
  frc::VictorSP rightIntake{1};
```
Motorları iki adet VictorSP kontrol ediyor. İşlemi gerçekleştirmek için `intake()` methodunu Robot sınıfına dahil ettik.
```cpp
  //Robot.cpp
  void Robot::intake()
  {
    if(js.GetPOV()==180)
    {
      rightIntake.Set(-1.0);
      leftIntake.Set(1.0);
    }
    else if(js.GetPOV()==0)
    {
      rightIntake.Set(1.0);
      leftIntake.Set(-1.0);
    } 
    else
    {
      rightIntake.Set(0.0);
      leftIntake.Set(0.0);
    } 
  }
```
Method 2 adet Joystick butonundan gelen inputları kontrol ediyor ve butona göre motorları dışa veya içe doğru çeviriyor. Bu şekilde cargo alıp atabiliyor. Bunları yaparken Victor motor sürücü sınıfının `Set()` methodunu kullanarak PWM sinyalleri ile motor sürücü ile haberleşiliyor. Motor sürücülerin kontrolü için aşağıdaki linklerden yararlanabilirsiniz. 

[PWM kullanan motor sürücüleri ile motor sürme hakkında bilgi](https://wpilib.screenstepslive.com/s/currentCS/m/cpp/l/241859-driving-motors-with-pwm-speed-controller-objects) \
[Motor sürücülerin dokümentasyonu (örnek olarak VictorSP)](https://first.wpi.edu/FRC/roborio/release/docs/cpp/classfrc_1_1VictorSP.html)
- ## Intake Hatch Asma Sistemi
Hatch alırken intake'in üst kısmında bulunan velcrolardan yararlandık. Daha sonra yapışan hatchleri rocket ve cargo ship'e asarken ise 1 adet piston kullandık.
```cpp
void hatchStuff();
frc::DoubleSolenoid hatchThrow{6,7}; //PCM channels
```
Yine operasyon için kullandığımız `hatchStuff()` methodunu ve piston kontrolü için `DoubleSolenoid` objesini robot sınıfına dahil ettik.
```cpp
void Robot::hatchStuff()
{
  if(js.GetRawButton(12))
  {
    hatchThrow.Set(frc::DoubleSolenoid::Value::kForward);
  }
  else if(js.GetRawButton(11))
  {
    hatchThrow.Set(frc::DoubleSolenoid::Value::kReverse);
  }
  else
  {
   hatchThrow.Set(frc::DoubleSolenoid::Value::kOff);
  }
}
```
Method joystick butonlarına göre pistonu ileri veya geri hareket ettiriyor. Böylece pistonu ileri pozisyona alıp hatch'i asabiliyoruz. Astıktan sonra ise içeri alıp bir sonraki hedefe hazır hale getiriyoruz.
# Ekstra Kontrol Sistemleri
Joystick hazırlama - esadın repoya link ver. \
Otonom çalışması ve fikri.

# Son notlar
