# MeanShift
Mean shift algoritması yani ortalama kaydırmalı bir kümeleme algoritmasıdır.
Bu algoritma bir yoğunluk fonksiyonunun maksimumlarını bulmak için parametrik olmayan bir öznitelik uzayı matematiksel analiz tekniğidir.
Her bir iterasyonda, daha yüksek yoğunluklu bölgelere kaydırılır.

# AVANTAJLARI
- Küme sayısının önceden belirtilmesi gerekmez.
- Prosedür, tek bir parametrenin seçimine dayanır: bant genişliği.
- Veri kümelerinde önceden tanımlanmış herhangi bir şekil almaz.
- İsteğe bağlı özellik alanlarını yönetebilir.

# DEZAVANTAJLARI
- Çok yavaş
- Pencere boyutu/yarıçapı -r- seçimi önemsiz olabilir.
- En büyük dezavantajı, hesaplama açısından maliyetli olmasıdır. ( O(n²) )
