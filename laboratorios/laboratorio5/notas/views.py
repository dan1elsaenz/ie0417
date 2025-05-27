from django.shortcuts import render, redirect, get_object_or_404

from .models import Nota

def lista_notas(request):
    notas = Nota.objects.all()
    return render(request, 'notas/lista.html', {'notas': notas})

def crear_nota(request):
    if request.method == 'POST':
        titulo = request.POST.get('titulo')
        contenido = request.POST.get('contenido')
        if titulo and contenido:
            Nota.objects.create(titulo=titulo, contenido=contenido)
            return redirect('lista_notas')
    return render(request, 'notas/crear.html')

def eliminar_nota(request, nota_id):
    nota = get_object_or_404(Nota, id=nota_id)
    nota.delete()
    return redirect('lista_notas')
