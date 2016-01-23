const int sensorPin = A0; // المنفذ الذي سيتحسس التغير في قيمة فرق الجهد نتيجة تغير المقاومة
const int ledPin = 5; // المنفذ المسؤول عن إشعال الثنائي الضوئي


int sensorValue; 
boolean c=0; // لنتحسس حركة العملة

static int CM=0;


void setup(){
  
 
 Serial.begin(9600);
 pinMode(ledPin,OUTPUT); 
 digitalWrite(ledPin,HIGH); // أمر إشعال الثنائي الضوئي
 delay(5000); // تأخير لمدة 5 ثوان لتستقر قيمة المقاومة

}


void loop(){
  
 
  
 
 sensorValue = analogRead(sensorPin) ; // قراءة قيمة فرق جهد المنفذ التماثلي الذي قمنا بتوصيله إلى طرف المقاومة الحساسة للضوء
   
 Serial.println(sensorValue);
 Serial.print(" LDR sensor  Value");


 // إذا حجبت العملة ضوء الثنائي الضوئي ستنخفض قيمة فرق الجهد
 if (sensorValue<=20 && c==false){
  c=true; // هذا يعني أن العملة قد دخلت جزئيا وحجبت الشعاع الضوئي المنبعث من الثنائي
  delay(1000);
}

// إذا كانت العملة قد حجبت ضوء الثنائي من قبل و أصبحت قيمة فرق الجهد مرتفعة مرة أخرى
if (c==true && sensorValue >50)
{

  c=false; // هذا يعني أن العملة قد نزلت إلى الأسفل ورجع ضوء الثنائي ليؤثر على قيمة المقاومة


  Serial.println();
  Serial.print("-| Enjoy ");
  Serial.print(++CM);
  Serial.print(" $ |- ");
 
  
}

}
  
