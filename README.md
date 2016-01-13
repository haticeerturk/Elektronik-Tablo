Elektronik tablo (Spreadsheet), her bir hücresinde ya bir sayı ya da bir formül içerir. Formül diğer hücrelerdeki değerleri kullanarak belli hesaplamalar yapar.<br/>
Girdi tablosu bir karakter dizisi olarak verilecek ve yazdığınız programa aynen kopyalanıp yapıştırılacaktır.<br/>
Aşağıdaki örnek girdi dizisini kodunuza ekleyerek kullanabilirsiniz.<br/>
Örneğin :<br/>
char girdi[] = "4,3,10,34,37,=A1+B1+C1,40,17,34,=A2+B2+C2,=A1+A2,=B1+B2,=C1+C2,=D1+D2";<br/>
● Girdi değerleri virgül (,) karakteri ile ayrılır.<br/>
● Girdinin ilk iki değeri elektronik tablonun sütun ve satır sayısını ifade eder. Bu sütun ve satır sayısı en fazla 10 olabilir.<br/>
● Bu iki değerden sonra elektronik tablodaki hücrelerin değerleri satır satır sıralı olarak verilir. Bir hücre ya bir sayı ya da bir formül içerir. Bir formül ifadesi (=) karakteri ile başlar ve hiç boşluk karakteri içermez. Formül içerisinde toplama(+), çıkarma(-), çarpma(*) ve bölme(/) işlemleri yapılabilir.<br/>
● Sütunlar A-J arasındaki 10 harf (A,B,C,D,E,F,G,H,I,J) ile ifade edilir. Satırlar ise [1-10] aralığındaki değerler ile ifade edilir.<br/>
Aşağıdaki fonksiyonlar, kullanıcıya seçim yapabileceği bir menü olarak sunulmalıdır. Her işlem bitiminde kullanıcıya bu menü tekrar gösterilir ve seçim yapması beklenir. Menüde programdan çıkmak için de bir seçenek bulunmalıdır.<br/><br/>
Formül hesaplama fonksiyonu :<br/>
Tabloda formül ile temsil edilen hücrelerin değerlerini hesaplayıp bu hesaplanmış değerlerle tabloyu ekrana yazdırır.<br/>
Örnek girdi:<br/>
char girdi[]="4,3,10,34,37,=A1+B1+C1,40,17,34,=A2+B2+C2,=A1+A2,=B1+B2,=C1+C2,=D1+D2";<br/>
Örnek çıktı:<br/>
10, 34, 37, 81<br/>
40, 17, 34, 91<br/>
50, 51, 71, 172<br/><br/>
Satır ekleme fonksiyonu<br/>
Eğer tablo 10 satır sınırına ulaştıysa kullanıcıya uyarı verecektir ve yeni satır eklemeyecektir. Ulaşmadıysa yeni bir satırı tabloya şu şekilde ekleyecektir:<br/>
1. Kullanıcıya, yeni satırın tabloda hangi satırdan sonra ekleneceğini sor. Kulanıcının girdiği değer eğer tabloda bulunmayan bir satırı ifade ediyor ise tekrar sor.<br/>
2. Sütun sayısı kadar elemanın değerini kullanıcıdan alıp satırdaki elemanların değeri olarak tabloya ekle.<br/>
3. Yeni satır eklenmiş haliyle birlikte tabloyu ekrana yazdır.<br/><br/>
Satır silme fonksiyonu<br/>
1. Kullanıcıya silinmesi istenen satır numarasını sor.<br/>
2. Satırı tablodan kaldır.<br/>
3. Tablonun son halini ekrana yazdır.<br/><br/>
Hücre değeri girme veya güncelleme fonksiyonu<br/>
1. Kullanıcıdan değiştirilmek istenen hücrenin sütun değeri (A-J aralığında) ve satır değerini ([1-10] aralığında) al. Girilen değere karşılık gelen bir hücre yok ise tekrar sor.<br/>
2. Kullanıcıya hücrenin yeni değerini sor ve tablodaki değeri bu yeni değerle değiştir.<br/>
3. Tablonun son halini ekrana yazdır.<br/><br/>
Veri filtreleme fonksiyonu<br/>
1. Kullanıcıdan tabloda filtrelenmesi istenen değeri sor.<br/>
2. Tabloyu değiştirmeden, sadece bu değere eşit veya küçük olan hücre değerlerini (formüller hariç) “!” ünlem karakteri ile gösterecek şekilde ekrana yazdır.<br/>
Tablo:<br/>
10, 34, 37, 81<br/>
40, 17, 34, 91<br/>
50, 51, 71, 172<br/>
Kullanıcı filtrelenecek değer olarak 30 girdiyse<br/>
Örnek çıktı:<br/>
!, 34, 37, 81<br/>
40, !, 34, 91<br/>
50, 51, 71, 172<br/>
