# Django

### Project structure:
```py
mysite/
    manage.py
    mysite/
        __init__.py
        settings.py
        urls.py
        wsgi.py
```
- **Outer mysite**: Project directory, can rename it to anything 
- **Manage.py**: Utility for interacting with project
- **Inner mysite**: Actual python package for your project
- **mysite/\_\_init\_\_.py**: To tell python that inner mysite is a module
- **mysite/urls.py**: Url declarations

### Apps:
- Each app is written as a python package
- Project vs Apps: 
    * An app is a web application.
    * A project is a collection of configuration and *apps* for a particular website
    * A project can contain multiple apps

### Django applications on heroku:
- **Database configuration**:
    * 
    
### Models:
- Each model maps to a single database table
- Each model is a python class that subclasses django.db.models.Model
- Each attribute of the model represents a database field
- 
### TODO: 
- [https://docs.djangoproject.com/en/1.11/topics/install/#install-apache-and-mod-wsgi](Django in deployement, apache and mod-wsgi)
- 

