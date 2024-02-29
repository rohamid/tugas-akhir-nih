// Ini buat menghitung index gambar dari 0 sampai 11
// terus balik lagi ke 0
if(indexGAM.val<11)
{
    indexGAM.val=indexGAM.val+1
}
else 
{
    indexGAM.val=0
}

// Sesuaikan dengan index gambarnya
if(indexGAM.val==0) 
{
    picGERAK.pic=1
}
if(indexGAM.val==1) 
{
    picGERAK.pic=2
}
if(indexGAM.val==2) 
{
    picGERAK.pic=3
}
// Terus sampe sesuai dengan jumlah gambar