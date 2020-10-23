# Converting CSV file to VCF file for [Bilgisayar ve Bilişim Teknolojileri Kulübü](http://bbtk.ogu.edu.tr/)

## Excel save order
---------------------------------------------------------------------------------------------
|  NAME	 |   SURNAME  | STUDENT ID  | DEPARTMENT |   PHONE NUMBER   |       E-MAIL          | 
|--------|------------|-------------|------------|------------------|-----------------------|
|  ARDA	 |    USLU    | 22222222222 | Bil. Müh.  |   22222222222    |usluarda58@gmail.com   | 
|  SİNA  |   KUŞOĞLU  | 22222222223 | Bil. Müh.  |   32222222222    |sina.kusoglu@gmail.com |
|  EDA   |    ÇAM     | 22222222224 | Bil. Müh.  |   42222222222    |caam.edaa@gmail.com    |
---------------------------------------------------------------------------------------------

## CSV file format
> ARDA,USLU,22222222222,Bil. Müh.,22222222222,usluarda58@gmail.com

> SİNA,KUŞOĞLU,22222222223,Bil. Müh.,32222222222,sina.kusoglu@gmail.com

> EDA,ÇAM,22222222224,Bil. Müh.,42222222222,caam.edaa@gmail.com

## VCF file output
```
BEGIN:VCARD
VERSION:3.0N;CHARSET=utf-8:USLU BBTK2020;ARDA;;;;
FN;CHARSET=utf-8:ARDA USLU BBTK2020
ORG:BBTK
TEL;TYPE=WORK,MOBILE:022222222222
EMAIL:usluarda58@gmail.com
END:VCARD
```

* Name format is ARDA USLU BBTK{year}
