# Myrepository
Myrepository

* this is the respository of my self-made .   
* only support 51 project now.
## how to use the res.xml
* add a   &lt; respository &gt; in the `<repositorys> `  

* the name means the name of this package ,

* file name means the file's name such as 

    ```xml
    <respository>
        <name>
            AT24C02
        </name>
        <path>
            D:\OneDrive - jxstnu.edu.cn\keil\respocity\AT24C02\
        </path>
        <fileName>
            ATC02
        </fileName>
        <dependent>
    			I2C
    		</dependent>
    </respository>
    ```
* the package name  _AT24C02_ but the file it contains is *ATC02.c*  and *ATC02.h* 

* the dependent means the package 's dependent package name , such as atc02 must add the I2C first.

* the `only` attribute if `only='c'` mean this package only have .c file 

    * `only='h'`means only have .h file
    * `only='d'` means no any .c or .h file only a combom of packages
    * use : `<respository only='c'>`

## how to use the wmake.txt

```txt
buildFile Project.uvproj
setResP D:\OneDrive - jxstnu.edu.cn\keil\respocity\
setIncludeHand STC32G.h
addC main.c,atk.c
addH SSS.h
use Air724,STC32S,SHT35,MPU6050,AT24C02,CAR
addD test,groupname

```

* command `setResP` means set the path of your res.xml saved
* `setIncludeHand` will autoly replace the *.c* file in the resposity let them include the parament
* `addC` means add the .c file to the *Project.urject* now the name of this file was unchange able use the *','* to spilt
* `addH ` same as `addC ` just this add the .h file
* `use` means add dependent package, the name was the package name saved in the res.xml. use the ',' to spilt , auto add the dependent attribute in the res.xml ,this command used to name `addD`
* `addD {path},{groupname}` this command means that you can add all the file of that  direction to the keil project file.And it will auto add a group of that .the arg groupname is the name
*  `buildFile {filename}` this is used to specify the project file for compilation. Must put in the first line. Auto add a _"./“_  in front of the filename

