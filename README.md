# Descripción

¿Alguna vez te preguntaste como cifrar mensajes utilizando multiplicación de matrices? No te preocupes, nosotros tampoco, pero hoy te vamos a contar un poco sobre como podrías hacerlo utilizando una técnica denominada **Cifrado de Hill**. 

# Tutorial

Es simple. Desarrollamos un algoritmo en C que te permite **encriptar** y **desencriptar** cadenas de texto utilizando una matriz llave cuadrada de dimensión 3. 

```
Si queres ingresar un mensaje para encriptar marca 0.
Si queres ingresar un mensaje para desencriptar marca 1.
```

### Encriptar

```
Elijo la opcion: 0
Encendiendo encriptador...
Encriptador encendido, ingresar mensaje para encriptar: Somos campeones del mundo.
Cadena ingresada: Somos campeones del mundo.
Encriptando cadena...
Cadena encriptada: I^Lu▬:P>▬d♣xa‼xy|9§y0P
```

### Desencriptar

```
Elijo la opcion: 1
Encendiendo desencriptador...
Desencriptador encendido, ingresar mensaje para desencriptar: I^Lu▬:P>▬d♣xa‼xy|9§y0P
Cadena ingresada: I^Lu▬:P>▬d♣xa‼xy|9§y0P
Desencriptando cadena...
String length: 22
Cadena desencriptada: Som5s$T☺Wies del↓<♥F6T
```
> Notar que aún se presentan errores de presición al trabajar con cadenas ASCII de representación en 7 bits. 

# Historial


# Colaboradores
- [Ivan Barrios]()
- [Valeria García]()
- [Bautista García]()
- [Joaquin Gavernet]()
- [Taciano Pacchialat]()


# Bibliografía

Material audiovisual complementario: <br><br>
<a href="http://www.youtube.com/watch?feature=player_embedded&v=-EQ8UomTrAQ" target="_blank"><img src="http://img.youtube.com/vi/-EQ8UomTrAQ/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

<a href="http://www.youtube.com/watch?feature=player_embedded&v=JK3ur6W4rvw" target="_blank"><img src="http://img.youtube.com/vi/JK3ur6W4rvw/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

<a href="http://www.youtube.com/watch?feature=player_embedded&v=6T46sgty4Mk" target="_blank"><img src="http://img.youtube.com/vi/6T46sgty4Mk/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>
