# Kaynaklar ve genel linkler

***Kodun dokümentasyonu için:[Wiki⬈](https://github.com/exeokan/KelRot-5655-Deep-Space-Code/wiki)*** \
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
 [FRC Programming Done Right](https://frc-pdr.readthedocs.io/en/latest/index.html) \
 [FRC resmi Discord grubu](https://discordapp.com/invite/frc) \
 [r/FRC](https://www.reddit.com/r/FRC/)

# Robot ve oyun hakkında
Robot, FRC'de her sene olduğu gibi yaklaşık 2.5 dakikalık bir oyunu oynayacak ve içerisindeki görevleri tamamlayacak şekilde tasarlandı ve yapıldı. Kodlanan sistemlerin mantığını daha iyi kavramak için oyun hakkında bilgi sahibi olmanızı tavsiye ederiz. Eğer Deep Space temalı bir FRC etkinliğinde katılımcı iseniz [Game Manuel'i](https://firstfrc.blob.core.windows.net/frc2019/Manual/2019FRCGameSeasonManual.pdf) detaylı şekilde okumanız beklenir. \
[Oyunun kısa tanıtım videosu](https://www.youtube.com/watch?v=Mew6G_og-PI) \
[Daha detaylı bilgi için kaynak merkezi](https://www.firstinspires.org/resource-library/frc/competition-manual-qa-system)

Kısa şekilde anlatmak gerekirse robotun [Cascade](https://www.instructables.com/id/Introduction-to-Manipulators/)???düzeltme pls  tipinde bir asansör ile taşınan ve cargo ile hatch taşıyıp yerleştiren bir intake sistemine sahip olacak şekilde yapılmasına takımca karar verildi. Oyunun sonundaki tırmanma görevine hitaben ise bir sistem yapılmadı.

! Robot renderı hoş olur.
