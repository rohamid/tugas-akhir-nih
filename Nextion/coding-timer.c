// Ini buat menghitung index gambar dari 0 sampai 11
// terus balik lagi ke 0
if(indexGAM.val<11)
{
    indeksGAM.val=indeksGAM.val+1
}
else 
{
    indeksGAM.val=0
}

// Sesuaikan dengan index gambarnya
if(indeksGAM.val==0) 
{
    picGERAK.pic=1
}
if(indeksGAM.val==1) 
{
    picGERAK.pic=2
}
if(indeksGAM.val==2) 
{
    picGERAK.pic=3
}
// Terus sampe sesuai dengan jumlah gambar