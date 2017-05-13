# LS-05-02-2017-1324486

## Codigo: 1324486

Ejercicios de la clase 05-02-2017 - Plataformas a Gran Escala

Informe: https://docs.google.com/a/correounivalle.edu.co/document/d/1wAUx-uNzeLKlAsj_mh_6QzmdjM67CXgPygONuaRftHo/edit?usp=sharing

Informe 2: https://docs.google.com/a/correounivalle.edu.co/document/d/1eqTSpvuuFuFr2Bj3WZGI1ENyfIW_n1NAESENflPKzTc/edit?usp=sharing


### Axb.c

- __Función: distributereceive__  
Mientras hayan filas por enviar (while), se envían tantas filas como procesos hayan disponibles (1er for), después se esperan tantas respuestas como filas se hayan enviado (3er for), todo esto mientras aún hayan filas que enviar como ya se habia mencionado. Por último se envía el mensaje de parada a todos los procesos cuando ya se acaben las filas (4to for).

- __Función: receive__  
Primero hay un MPI_Recv inicial para recibir el vector b enviado por la función sendvector, después dentro de un while true espera por mensajes del proceso maestro, es decir, siempre espera recibir mas filas hasta que recibe un mensaje de parada, si recibe una fila entonces realiza la operación correspondiente y envía la respuesta, si recibe un mensaje de parada, el proceso sale del while true y finaliza su ejecución. Para diferenciar entre mensajes se hace uso de __Stat.MPI_TAG__ y para recibir cualquier tipo de mensaje se hace uso de __MPI_ANY_TAG__.
